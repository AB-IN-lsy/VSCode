/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-31 17:24:25
 * @FilePath: \Acwing\96cp\c\c.cpp
 * @LastEditTime: 2023-03-31 20:24:21
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

struct Tree
{
    int l, r, suma, sumb;
} tr[N << 2];

int w[N], n, k, a, b, q;

void pushup(int p)
{
    tr[p].suma = tr[ls].suma + tr[rs].suma;
    tr[p].sumb = tr[ls].sumb + tr[rs].sumb;
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}

void update(int p, int L, int v)
{
    if (tr[p].l == L && tr[p].r == L)
    {
        w[L] += v;
        tr[p].suma = min(w[L], a);
        tr[p].sumb = min(w[L], b);
        return;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    if (L <= mid)
        update(ls, L, v);
    if (L > mid)
        update(rs, L, v);
    pushup(p);
}

int query(int p, int L, int R, int flag)
{
    if (tr[p].l >= L && tr[p].r <= R)
    {
        return !flag ? tr[p].suma : tr[p].sumb;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    int res = 0;
    if (L <= mid)
        res += query(ls, L, R, flag);
    if (R > mid)
        res += query(rs, L, R, flag);
    return res;
}

signed main()
{
    IOS;
    cin >> n >> k >> a >> b >> q;
    build(1, 1, n);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            update(1, x, y);
        }
        else
        {
            int p;
            cin >> p;
            cout << query(1, 1, p - 1, 1) + query(1, p + k, n, 0) << '\n';
        }
    }
    return 0;
}
