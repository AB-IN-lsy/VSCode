/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-11 18:22:37
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-11 19:33:48
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define MP                          make_pair
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , LL>              PII;


namespace dijkstra{
    const int N = 1e6 + 10;
    const LL INF = 0x3f3f3f3f3f3f3f3fll;
    priority_queue <PII, vector<PII>, greater<PII>> q;

    struct Edge
    {
        int u, v, w, next;
    }edge[N << 2];

    int h1[N], h2[N];
    
    int cnt;
    void init(){
        memset(h1, -1, sizeof h1);
        memset(h2, -1, sizeof h2);
        cnt = 0;
    }
    void add_edge(int u, int v, int w, int h[])
    {
        edge[cnt].u = u;
        edge[cnt].v = v;
        edge[cnt].w = w;
        edge[cnt].next = h[u];
        h[u] = cnt++;
    }
    LL dist1[N], dist2[N];
    bool vis[N];
    void dij(int s, int v, LL d[], int h[]){
        // 从s开始，v为s自带的初始值
        memset(vis, 0, sizeof vis);
        memset(d, 0x3f, sizeof dist1);
        d[s] = v;
        q.push( (sa) {s, v});
        while(!q.empty())
        {
            sa ns = q.top();
            q.pop();
            int x = ns.pos;
            if(vis[x]) continue;
            vis[x] = 1;
            for(int i = h[x]; ~i ; i = edge[i].next)
            {
                int to = edge[i].v;
                LL dd = d[x] + edge[i].w;
                if(d[to] > dd)
                {
                    d[to] = dd;
                    q.push( (sa) {to, d[to]});
                }
            }
        }
    }
}
using namespace dijkstra;

int radio[N];
int main()
{
    IOS;
    init();
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i ++){
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        add_edge(u, v, c, h1);
        add_edge(v, u, d, h2);
    }
    for(int i = 1; i <= n; i ++) cin >> radio[i];
    dij(1, 0, dist1, h1);
    dij(n, 0, dist2, h2);

    multiset <LL> s;
    for(int i = 1; i <= n; i ++){
        if(dist1[i] != INF && dist2[i] != INF){
            s.insert(dist1[i] + (dist2[i] + radio[i] - 1) / radio[i]);
        }
    }
    while(q --){
        int a, b;
        cin >> a >> b;
        if(dist1[a] != INF && dist2[a] != INF){
            s.erase(s.find(dist1[a] + (dist2[a] + radio[a] - 1) / radio[a]));
            radio[a] = b;
            s.insert(dist1[a] + (dist2[a] + radio[a] - 1) / radio[a]);
        }
        cout << *s.begin() << endl;
    }
    return 0;
}