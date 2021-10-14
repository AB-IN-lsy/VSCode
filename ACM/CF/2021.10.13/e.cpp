/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-14 00:12:16
 * @FilePath: \ACM\CF\2021.10.13\e.cpp
 * @LastEditTime: 2021-10-14 00:39:34
 */
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
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
vector<int> vv[N];
int deg[N], tag[N], dis[N];
void solve()

{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        deg[i] = 0;
        tag[i] = 0;
        dis[i] = 0;
        vv[i].clear();
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        vv[u].push_back(v);
        vv[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (deg[i] <= 1)
        {
            tag[i] = 1;
            q.push(i);
            dis[i] = 1;
        }
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : vv[u])
        {
            if (deg[v] <= 1)
                continue;
            deg[v]--;
            dis[v] = dis[u] + 1;
            if (deg[v] <= 1)
                q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dis[i] <= k)
            ans++;
    }
    cout << n - ans << '\n';
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