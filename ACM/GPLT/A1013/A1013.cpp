/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-03 14:57:08
 * @FilePath: \GPLT\A1013\A1013.cpp
 * @LastEditTime: 2022-09-03 15:49:12
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> g[N], st(N);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int u, int q) {
        for (auto v : g[u])
        {
            if (v == q || st[v])
                continue;
            st[v] = 1;
            dfs(v, q);
        }
    };

    auto check = [&](int q) {
        vector<int>(N).swap(st); // st清0
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == q || st[i])
                continue;
            dfs(i, q);
            cnt++;
        }
        return cnt - 1;
    };

    for (int i = 1; i <= k; ++i)
    {
        int q;
        cin >> q;
        cout << check(q) << '\n';
    }
    return 0;
}