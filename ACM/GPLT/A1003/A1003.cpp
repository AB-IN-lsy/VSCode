/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-30 21:32:59
 * @FilePath: \GPLT\A1003\A1003.cpp
 * @LastEditTime: 2022-08-30 21:48:29
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
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<int> p(N), dist(N, INT_MAX), st(N), pw(N), num(N);
    vector<PII> g[N];
    auto dij = [&](int s) {
        dist[s] = 0, pw[s] = p[s], num[s] = 1; // 初始化
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({0, s});
        while (SZ(q))
        {
            auto t = q.top();
            q.pop();
            int u = t.second;
            if (st[u])
                continue;
            st[u] = 1;

            for (auto [v, w] : g[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    num[v] = num[u];
                    pw[v] = pw[u] + p[v];
                    // 这里是更新，所以不能加等于
                    q.push({dist[v], v});
                }
                else if (dist[v] == dist[u] + w)
                {
                    num[v] += num[u];
                    if (pw[v] < pw[u] + p[v])
                    {
                        pw[v] = pw[u] + p[v];
                    }
                }
            }
        }
    };

    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dij(s);
    cout << num[d] << " " << pw[d] << '\n';

    return 0;
}