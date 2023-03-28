/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-28 17:42:13
 * @FilePath: \Acwing\243\243.cpp
 * @LastEditTime: 2023-03-28 18:00:57
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;
#define ls p << 1
#define rs p << 1 | 1

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

struct sa
{
    int l, r, dt, sum;
} tr[N << 2];
int a[N];

void pushup(int p)
{
    tr[p].sum = tr[ls].sum + tr[rs].sum;
}
void pushdown(int p)
{
    tr[ls].dt += tr[p].dt;
    tr[rs].dt += tr[p].dt;
    tr[ls].sum += (tr[ls].r - tr[ls].l + 1) * tr[p].dt;
    tr[rs].sum += (tr[rs].r - tr[rs].l + 1) * tr[p].dt;
    tr[p].dt = 0;
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, a[l]};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}

void update(int p, int L, int R, int v)
{
    if (tr[p].l >= L && tr[p].r <= R)
    {
        tr[p].dt += v;
        tr[p].sum += (tr[p].r - tr[p].l + 1) * v;
        return;
    }
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1;
    if (L <= mid)
        update(ls, L, R, v);
    if (R > mid)
        update(rs, L, R, v);
    pushup(p);
}

int query(int p, int L, int R)
{
    if (tr[p].l >= L && tr[p].r <= R)
    {
        return tr[p].sum;
    }
    pushdown(p);
    int res = 0;
    int mid = tr[p].l + tr[p].r >> 1;
    if (L <= mid)
        res += query(ls, L, R);
    if (R > mid)
        res += query(rs, L, R);
    return res;
}
int n, m;
signed main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'C')
        {
            int l, r, d;
            cin >> l >> r >> d;
            update(1, l, r, d);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, l, r) << '\n';
        }
    }
    return 0;
}