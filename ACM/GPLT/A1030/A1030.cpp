/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 18:28:22
 * @FilePath: \GPLT\A1030\A1030.cpp
 * @LastEditTime: 2023-01-07 19:12:42
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

#undef N
const int N = 510, INF = 0x3f3f3f3f;

#undef int
int n, m, s, d;
int dist[N], st[N], cost[N], pre[N];

struct sb
{
    int v, w, c;
};

vector<sb> g[N];

struct sa
{
    int d, c, u;

    bool operator<(const sa &t) const
    {
        if (d != t.d)
            return d > t.d;
        return c > t.c;
    }
};

void dij()
{
    memset(dist, 0x3f, sizeof dist);
    memset(pre, -1, sizeof pre);
    priority_queue<sa> q;
    dist[s] = 0, cost[s] = 0;
    q.push({0, 0, s});

    while (SZ(q))
    {
        auto t = q.top();
        auto u = t.u;
        q.pop();
        if (st[u])
            continue;
        st[u] = 1;
        for (auto &[v, w, c] : g[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                cost[v] = cost[u] + c;
                pre[v] = u;
                q.push({dist[v], cost[v], v});
            }
            if (dist[u] + w == dist[v] && cost[u] + c < cost[v])
            {
                cost[v] = cost[u] + c;
                pre[v] = u;
                q.push({dist[v], cost[v], v});
            }
        }
    }
}

signed main()
{
    IOS;
    cin >> n >> m >> s >> d;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        g[u].push_back({v, w, c});
        g[v].push_back({u, w, c});
    }
    dij();
    int d1 = d;
    vector<int> path;
    while (~d)
    {
        path.push_back(d);
        d = pre[d];
    }
    reverse(path.begin(), path.end());

    for (auto &u : path)
        cout << u << " ";
    cout << dist[d1] << " " << cost[d1];
    return 0;
}