/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-19 15:23:55
 * @FilePath: \ACM\GPLT\L2-001.CPP
 * @LastEditTime: 2022-04-19 15:52:36
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1010;

int st[N], dist[N], ww[N], num[N], people[N], pre[N];
vector<PII> g[N];

void dij(int s)
{
    memset(pre, -1, sizeof pre);
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    ww[s] = people[s];
    num[s] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    while (q.size())
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
                ww[v] = ww[u] + people[v];
                pre[v] = u;
                q.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w)
            {
                num[v] += num[u];
                if (ww[v] < ww[u] + people[v])
                {
                    ww[v] = ww[u] + people[v];
                    pre[v] = u;
                }
            }
        }
    }
}

signed main()
{
    IOS;
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; ++i)
        cin >> people[i];
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dij(s);

    cout << num[d] << " " << ww[d] << '\n';
    vector<int> path;
    while (d != -1)
    {
        path.push_back(d);
        d = pre[d];
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < SZ(path); ++i)
    {
        cout << path[i] << " "[i == SZ(path) - 1];
    }
    return 0;
}