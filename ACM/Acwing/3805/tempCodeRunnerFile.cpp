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
#define ls p << 1
#define rs p << 1 | 1

typedef pair<int, int> PII;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

struct sa
{
    int l, r, dt, mn;
};
sa tr[N << 2];
int a[N];

void pushup(int p)
{
    tr[p].mn = min(tr[ls].mn, tr[rs].mn);
}

void pushdown(int p)
{
    tr[ls].dt += tr[p].dt;
    tr[rs].dt += tr[p].dt;
    tr[ls].mn += tr[p].dt;
    tr[rs].mn += tr[p].dt;
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

void update(int p, int L, int R, int d)
{
    if (tr[p].l >= L && tr[p].r <= R)
    {
        tr[p].dt += d;
        tr[p].mn += d;
        return;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    pushdown(p);
    if (L <= mid)
        update(ls, L, R, d);
    if (R > mid)
        update(rs, L, R, d);
    pushup(p);
}

int query(int p, int L, int R)
{
    if (tr[p].l >= L && tr[p].r <= R)
    {
        return tr[p].mn;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    pushdown(p);
    int res = INF;
    if (L <= mid)
        res = min(res, query(ls, L, R));
    if (R > mid)
        res = min(res, query(rs, L, R));
    return res;
}

int n, m;
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, 1, n);

    scanf("%lld", &m);
    while (m--)
    {
        int l, r;
        char c;
        scanf("%lld %lld%c", &l, &r, &c);
        l++, r++;
        if (c == '\n')
        {
            if (l <= r)
                printf("%lld\n", query(1, l, r));
            else
                printf("%lld\n", min(query(1, 1, r), query(1, l, n)));
        }
        else
        {
            int d;
            scanf("%lld", &d);
            if (l <= r)
                update(1, l, r, d);
            else
                update(1, 1, r, d), update(1, l, n, d);
        }
    }
    return 0;
}