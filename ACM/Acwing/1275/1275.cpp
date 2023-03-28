/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-28 17:02:48
 * @FilePath: \Acwing\1275\1275.cpp
 * @LastEditTime: 2023-03-28 17:18:54
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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

struct sa
{
    int l, r, mx;
} tr[N << 2];

void pushup(int p)
{
    tr[p].mx = max(tr[ls].mx, tr[rs].mx);
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0};
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
        tr[p].mx = v;
        return;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    if (L <= mid)
        update(ls, L, v);
    if (L > mid)
        update(rs, L, v);
    pushup(p);
}

int query(int p, int L, int R)
{
    if (tr[p].l >= L && tr[p].r <= R)
    {
        return tr[p].mx;
    }
    int res = 0;
    int mid = tr[p].l + tr[p].r >> 1;
    if (L <= mid)
        res = max(res, query(ls, L, R));
    if (R > mid)
        res = max(res, query(rs, L, R));
    return res;
}

int m, p, cnt, a;
signed main()
{
    IOS;
    cin >> m >> p;
    build(1, 1, m);
    while (m--)
    {
        char op;
        int t;
        cin >> op >> t;
        if (op == 'A')
        {
            update(1, ++cnt, (t + a) % p);
        }
        else
        {
            a = query(1, max(1LL, cnt - t + 1), cnt);
            cout << a << '\n';
        }
    }
    return 0;
}