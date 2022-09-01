/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-31 20:20:01
 * @FilePath: \GPLT\A1004\A1004.cpp
 * @LastEditTime: 2022-08-31 20:27:43
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<int> g[N];
    for (int i = 1; i <= m; ++i)
    {
        int id, k;
        cin >> id >> k;
        for (int j = 1; j <= k; ++j)
        {
            int v;
            cin >> v;
            g[id].push_back(v);
        }
    }
    int mx = 0;
    vector<int> ans(N);
    function<void(int, int)> dfs = [&](int u, int d) {
        mx = max(mx, d);
        if (!SZ(g[u]))
        {
            ans[d]++;
            return;
        }
        for (auto v : g[u])
        {
            dfs(v, d + 1);
        }
    };
    dfs(1, 0);
    for (int i = 0; i <= mx; ++i)
    {
        cout << ans[i] << " ";
    }
    return 0;
}