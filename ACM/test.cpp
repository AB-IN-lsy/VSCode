/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-23 10:49:19
 * @FilePath: \ACM\test.cpp
 * @LastEditTime: 2021-10-03 13:51:44
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

namespace dij
{
    const int N = 1e7 + 10;
    const int INF = 0x3f3f3f3f;
    struct Edge
    {
        int u, v, w, ne;
    } e[N << 2];
    int h[N], cnt, dist[N], vis[N];

    void add(int u, int v, int w)
    {
        e[cnt].u = u;
        e[cnt].v = v;
        e[cnt].w = w;
        e[cnt].ne = h[u];
        h[u] = cnt++;
    }

    void dijkstra(int s, int d[])
    {
        memset(vis, 0, sizeof vis);
        memset(d, 0x3f, sizeof dist);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        d[s] = 0;
        q.push({0, s});
        while (q.size())
        {
            auto ns = q.top();
            q.pop();
            int x = ns.second;
            if (vis[x])
                continue;
            vis[x] = 1;
            for (int i = h[x]; ~i; i = e[i].ne)
            {
                int to = e[i].v;
                if (d[to] > d[x] + e[i].w)
                {
                    d[to] = d[x] + e[i].w;
                    q.push({d[to], to});
                }
            }
        }
    }
}
using namespace dij;
int a[N];
signed main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int mx = 0, tmp = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            if (mx < tmp)
            {
                ans = a[i - 1];
                mx = tmp;
            }
            tmp = 1;
        }
        else
        {
            tmp++;
        }
    }
    cout << ans << '\n';
}