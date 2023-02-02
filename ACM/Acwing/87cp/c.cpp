/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-29 21:45:16
 * @FilePath: \Acwing\87cp\c.cpp
 * @LastEditTime: 2023-01-29 22:04:13
 */
#pragma GCC optimize(1)
#pragma GCC optimize(2) // 先开优化
#pragma GCC optimize(3, "Ofast", "inline")
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int d1[N], d2[N];
vector<int> g[N];
int n, m, ans;

void dfs(int u, int fa)
{

    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        int dis = d1[v] + 1;
        if (dis > d1[u])
        {
            d2[u] = d1[u];
            d1[u] = dis;
        }
        else if (dis > d2[u])
        {
            d2[u] = dis;
        }
    }
    ans = max(ans, d1[u] + d2[u]);
}

signed main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);
    cout << ans;
    return 0;
}