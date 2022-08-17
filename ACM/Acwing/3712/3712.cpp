/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 11:01:52
 * @FilePath: \Acwing\3712\3712.cpp
 * @LastEditTime: 2022-08-17 15:06:25
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

void solve()
{
    int n, y, mx = 0;
    cin >> n >> y;

    vector<PII> g[N];
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        mx = max(mx, w);
    }

    int cnt = 0;
    function<void(int, int, int)> dfs = [&](int u, int fa, int x) {
        cnt++;
        for (auto [v, w] : g[u])
        {
            if (v == fa)
                continue;
            if (w >= x)
                dfs(v, u, x);
        }
    };

    auto check = [&](int x) {
        dfs(0, -1, x);
        return cnt <= y;
    };

    int l = 0, r = mx + 1;
    while (l < r)
    {
        cnt = 0;
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << '\n';

    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}