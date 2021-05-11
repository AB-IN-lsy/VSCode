#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define MP                          make_pair
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

namespace dij{
    const int N = 1e7 + 10;
    const int INF = 0x3f3f3f3f;
    struct Edge
    {
        int u, v, w, ne;
    }edge[N << 2];
    int h[N], cnt, dist[N], vis[N];

    void add(int u, int v, int w)
    {
        edge[cnt].u = u;
        edge[cnt].v = v;
        edge[cnt].w = w;
        edge[cnt].ne = h[u];
        h[u] = cnt++;
    }
    
    void dijkstra(int s, int d[]){
        memset(vis, 0, sizeof vis);
        memset(d, 0x3f, sizeof dist);
        priority_queue <PII, vector<PII>, greater<PII>> q;
        d[s] = 0;
        q.push({0, s}); 
        while(q.size())
        {
            auto ns = q.top();
            q.pop();
            int x = ns.second;
            if(vis[x]) continue;
            vis[x] = 1;
            for(int i = h[x]; ~i ; i = edge[i].ne)
            {
                int to = edge[i].v;
                if(d[to] > d[x] + edge[i].w)
                {
                    d[to] = d[x] + edge[i].w;
                    q.push({d[to], to});
                }
            }
        }
    }
}
using namespace dij;

int main()
{
    IOS;
    memset(h, -1, sizeof h);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dijkstra(1, dist);
    if(dist[n] == INF) cout << "-1" << endl;
    else cout << dist[n] << endl;
    return 0;
}