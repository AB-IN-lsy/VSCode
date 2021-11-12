#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef pair<int, int> PII;
#define ls i << 1
#define rs i << 1 | 1
const int INF = 0x3f3f3f3f;

namespace xds_add
{
const int N = 1e6 + 10;
LL a[N << 2], tr[N << 2], add_tag[N << 2], k;
int n, x, y;

inline void pushup(int i)
{
    tr[i] = tr[ls] + tr[rs];
}

void bulid(int i, int l, int r)
{
    add_tag[i] = 0;
    if (l == r)
    {
        tr[i] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(ls, l, mid);
    bulid(rs, mid + 1, r);
    pushup(i);
}

inline void ADD(int i, int l, int r, LL k)
{
    add_tag[i] = (add_tag[i] + k);
    tr[i] = (tr[i] + (r - l + 1) * k);
}

inline void pushdown(int i, int l, int r, int mid)
{
    if ((!add_tag[i]))
        return;
    ADD(ls, l, mid, add_tag[i]);
    ADD(rs, mid + 1, r, add_tag[i]);
    add_tag[i] = 0;
}

inline void update_ADD(int i, int l, int r, int x, int y, LL k)
{
    if (l > y || r < x)
        return;
    if (l >= x && r <= y)
        return ADD(i, l, r, k);
    int mid = (l + r) >> 1;
    pushdown(i, l, r, mid);
    update_ADD(ls, l, mid, x, y, k);
    update_ADD(rs, mid + 1, r, x, y, k);
    pushup(i);
}

LL query(int i, int l, int r, int x, int y)
{
    LL res = 0;
    if (l > y || r < x)
        return 0;
    if (l >= x && r <= y)
        return tr[i];
    int mid = (l + r) >> 1;
    pushdown(i, l, r, mid);
    if (x <= mid)
        res = res + query(ls, l, mid, x, y);
    if (y > mid)
        res = res + query(rs, mid + 1, r, x, y);
    return res;
}
} // namespace xds_add
using namespace xds_add;

PII c[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].first;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].second;
    }
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = c[i].first;
    }
    bulid(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        {
            if (c[i].second == 'R')
            {
                update_ADD(1, 1, 1, minx, n, 1);
            }
            if (c[i].second == 'B')
            {
                update_ADD(1, 1, 1, minx, a[i], 1);
            }
        }
    }

    signed main()
    {
        IOS;
        int t;
        cin >> t;
        while (t--)
        {
            solve();
        }
        return 0;
    }