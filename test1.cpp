/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-06 20:12:14
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-10 20:08:49
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define MP                          make_pair
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

namespace dijkstra{
    const int N = 1e6 + 10;
    const int inf = 0x3f3f3f3f;

    struct sa{
        int pos; // 位置
        int dis; // 距离
    };

    struct cmp{ // 重写函数
        bool operator() (const sa &a, const sa &b) const{
            return a.dis > b.dis;
        }    
    };

    priority_queue <sa, vector<sa>, cmp> q;
    
    struct Edge
    {
        int u, v, w, next;
    }edge[N << 2];
    int head[N];
    int cnt;
    void init(){
        memset(head, -1, sizeof(head));
        cnt = 0;
    }
    void add_edge(int u, int v, int w)
    {
        edge[cnt].u = u;
        edge[cnt].v = v;
        edge[cnt].w = w;
        edge[cnt].next = head[u];
        head[u] = cnt++;
    }
    int dis[N];
    bool vis[N];
    void dij(int s, int v, int d[]){
        // 从s开始，v为s自带的初始值
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= N; i++) d[i] = inf;
        d[s] = v;
        q.push( (sa) {s, v});
        while(!q.empty())
        {
            sa ns = q.top();
            q.pop();
            int x = ns.pos;
            if(vis[x]) continue;
            vis[x] = 1;
            for(int i = head[x]; ~i ; i = edge[i].next)
            {
                int to = edge[i].v;
                int dd = d[x] + edge[i].w;
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

int main()
{
    IOS;
    init();
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dij(s, 0, dis);

    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    
    return 0;
}