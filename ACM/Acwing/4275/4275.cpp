/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-20 23:39:01
 * @FilePath: \ACM\Acwing\4275\4275.cpp
 * @LastEditTime: 2022-06-21 09:41:00
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;

    vector<PII> g[n + 1];

    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto dij = [&](vector<int> qq) {
        int s = qq[0];

        vector<int> st(n + 1);
        vector<int> dist(n + 1, INF);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({0, s});
        dist[s] = 0;

        while (SZ(q))
        {
            auto [dis, u] = q.top();
            q.pop();

            if (st[u])
                continue;
            st[u] = 1;
            for (auto [v, w] : g[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < n - 1; ++i)
        {
            if (dist[qq[i]] > dist[qq[i + 1]])
                return 0;
        }
        return 1;
    };

    int k;
    vector<int> q(n);
    cin >> k;
    while (k--)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> q[i];
        }
        if (dij(q))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}