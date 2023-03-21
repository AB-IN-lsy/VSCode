/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-04 19:17:20
 * @FilePath: \Acwing\3305\3305.cpp
 * @LastEditTime: 2023-03-04 19:25:45
 */
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

const int N = 3e4 + 10, INF = 0x3f3f3f3f;

int n, m, k, t;
int a[N];
vector<PII> g[N];
int dist[N], st[N];
int vis[N];

void dij(int s)
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s] = 0;
    while (SZ(q))
    {
        auto [_, u] = q.top();
        q.pop();
        if (st[u])
            continue;
        st[u] = 1;
        for (auto &[v, w] : g[u])
        {
            if (dist[u] + w <= dist[v])
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return;
}

signed main()
{
    IOS;
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        g[0].push_back({x, 0});
    }

    for (int i = 1; i <= k; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int w = max(a[x], a[y]);
        g[x].push_back({z, w});
        g[y].push_back({z, w});
    }
    dij(0);
    cout << dist[t] << '\n';

    return 0;
}