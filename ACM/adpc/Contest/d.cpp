/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-27 11:41:44
 * @FilePath: \ACM\Contest\d.cpp
 * @LastEditTime: 2022-03-27 12:10:19
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 100;
int n, m, c, col[N];

vector<PII> G[N];
LL ans[N], res;

int son[N], cnt[N], sizx[N], bbb;

void dfs1(int x, int fa)
{
    sizx[x] = 1;
    son[x] = 0;
    for (int i = 0; i < SZ(G[x]); ++i)
    {
        int v = G[x][i].first;
        if (v == fa)
            continue;
        dfs1(v, x);
        sizx[x] += sizx[v];
        col[v] = G[x][i].second;
        if (sizx[v] > sizx[son[x]])
            son[x] = v;
    }
}

void calc(int x, int fa, int val)
{
    if (val == 1)
    {
        res += col[x] * col[x] * (2 * cnt[col[x]] + 1);
        cnt[col[x]] += 1;
    }
    else
        cnt[col[x]] -= 1;
    for (int i = 0; i < SZ(G[x]); ++i)
    {
        int v = G[x][i].first;
        if (v == fa || v == bbb)
            continue;
        calc(v, x, val);
    }
}

void dsu(int x, int fa, int op)
{
    for (int i = 0; i < SZ(G[x]); ++i)
    {
        int v = G[x][i].first;
        if (v == fa || v == son[x])
            continue;
        dsu(v, x, 0);
    }
    if (son[x])
    {
        dsu(son[x], x, 1);
        bbb = son[x];
    }
    calc(x, fa, 1);
    res -= col[x] * col[x] * (2 * cnt[col[x]] - 1);
    cnt[col[x]] -= 1;
    ans[x] = res;
    res += col[x] * col[x] * (2 * cnt[col[x]] + 1);
    cnt[col[x]] += 1;
    bbb = 0;
    if (op == 0)
    {
        calc(x, fa, -1);
        res = 0;
    }
}

signed main()
{
    IOS;
    cin >> n >> m >> c;
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(MP(v, w));
        G[v].push_back(MP(u, w));
    }
    dfs1(1, 0);
    dsu(1, 0, 0);
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}