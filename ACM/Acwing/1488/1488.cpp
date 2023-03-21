/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-04 16:16:41
 * @FilePath: \Acwing\1488\1488.cpp
 * @LastEditTime: 2023-03-04 16:44:53
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n, m, q, k;
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
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        int x;
        cin >> x;
        // 新增超级源点，连向所有商店
        g[0].push_back({x, 0});
    }
    dij(0);
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << dist[x] << '\n';
    }
    return 0;
}