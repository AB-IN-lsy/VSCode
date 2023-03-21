/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-02 14:50:44
 * @FilePath: \Acwing\456\456.cpp
 * @LastEditTime: 2023-03-02 15:17:51
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
int n, m;
bool st[N];
vector<PII> g[N];
int deg[N], dist[N];

signed main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int t, l = INF, r = -INF;
        cin >> t;
        for (int j = 1; j <= t; ++j)
        {
            int x;
            cin >> x;
            st[x] = true;
            l = min(l, x);
            r = max(r, x);
        }
        int ver = n + i;
        for (int j = l; j <= r; ++j)
        {
            if (st[j])
                g[ver].push_back({j, 1}), deg[j]++;
            else
                g[j].push_back({ver, 0}), deg[ver]++;
        }
    }
    // topsort
    queue<int> q;
    for (int i = 1; i <= n + m; ++i)
    {
        if (i <= n)
            dist[i] = 1;
        if (!deg[i])
            q.push(i);
    }
    int res = 0;
    while (SZ(q))
    {
        auto u = q.front();
        q.pop();
        for (auto &[v, w] : g[u])
        {
            dist[v] = max(dist[v], dist[u] + w);
            res = max(res, dist[v]);
            if (!--deg[v])
            {
                q.push(v);
            }
        }
    }
    cout << res << '\n';

    return 0;
}