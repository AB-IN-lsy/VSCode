/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-28 20:04:18
 * @FilePath: \Acwing\1228\1228.cpp
 * @LastEditTime: 2023-03-28 20:50:10
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f;

struct Tree
{
    int l, r, len, cnt;
} tr[N >> 3];

struct Line
{
    int x, y1, y2, flag;

    bool operator<(Line &a) const
    {
        return x < a.x;
    }
} seg[N];

int n, xs[N];

void pushup(int p)
{
    if (tr[p].cnt)
        tr[p].len = tr[p].r - tr[p].l;
    else
        tr[p].len = tr[ls].len + tr[rs].len;
}

void build(int p, int l, int r)
{
    tr[p] = {xs[l], xs[r], 0, 0};
    if (r == l + 1)
        return;
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid, r);
}

void update(int p, int L, int R, int v)
{
    if (tr[p].l >= R || tr[p].r <= L)
        return;
    if (tr[p].l >= L && tr[p].r <= R)
    {
        tr[p].cnt += v;
        pushup(p);
        return;
    }
    update(ls, L, R, v);
    update(rs, L, R, v);
    pushup(p);
}

signed main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        seg[i] = {x1, y1, y2, 1};
        seg[i + n] = {x2, y1, y2, -1};
        xs[i] = y1;
        xs[i + n] = y2;
    }
    n *= 2;

    sort(seg + 1, seg + 1 + n);
    sort(xs + 1, xs + 1 + n);

    build(1, 1, n);
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        update(1, seg[i].y1, seg[i].y2, seg[i].flag);
        ans += (seg[i + 1].x - seg[i].x) * tr[1].len;
    }
    cout << ans << '\n';
    return 0;
}