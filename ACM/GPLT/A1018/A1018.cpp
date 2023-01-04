/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-04 20:28:11
 * @FilePath: \GPLT\A1018\A1018.cpp
 * @LastEditTime: 2023-01-04 20:51:26
 */
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

int dist[N], st[N], c[N], bring = INF, send = INF, C, n, S, m;
vector<PII> g[N];
vector<int> path, ans;

void dij()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 0});
    dist[0] = 0;
    while (SZ(q))
    {
        auto t = q.top();
        q.pop();
        auto u = t.second;
        if (st[u])
            continue;
        st[u] = 1;
        for (auto &[v, w] : g[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return;
}

int main()
{
    cin >> C >> n >> S >> m;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    dij(); // 先做一遍dij

    path.push_back(0); // 路径加入起点

    function<void(int, int, int)> dfs = [&](int u, int s, int mins) {
        if (u)
        {
            s -= C / 2 - c[u];
            mins = min(mins, s);
        }
        if (u == S)
        {
            int sd = abs(min(mins, 0));
            int br = sd + s;

            if (sd < send)
            {
                ans = path;
                send = sd;
                bring = br;
            }
            else if (sd == send && br < bring)
            {
                bring = br;
                ans = path;
            }
        }
        for (auto &[v, w] : g[u])
        {
            if (dist[u] + w == dist[v])
            {
                path.push_back(v);
                dfs(v, s, mins);
                path.pop_back();
            }
        }
    };

    dfs(0, 0, 0);

    cout << send << " ";
    cout << ans[0];
    for (int i = 1; i < SZ(ans); ++i)
        cout << "->" << ans[i];
    cout << " " << bring;
    return 0;
}