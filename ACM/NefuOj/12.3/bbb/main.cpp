#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+10;

struct Edge{
    int u,v,next;
}edge[N<<2];

int head[N], vis[N];
int cnt;
ll a[N];

void add_edge(int u, int v){
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}

int n,m,u,v;
queue <int> q;
int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &u, &v);
        a[u] += v;
    }
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            if(vis[v]) continue;
            vis[v] = 1;
            a[v] += a[u];
            q.push(v);
        }
    }
    for(int i = 1; i <= n; i++){
        i == n ? printf("%lld\n", a[i]) : printf("%lld ", a[i]);
    }
    return 0;
}

/*
6 5
1 2
1 3
2 4
2 5
6 3
2 3
4 3
3 1
1 2
6 1
*/
