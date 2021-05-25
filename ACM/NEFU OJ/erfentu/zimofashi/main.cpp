#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Edge
{
    int u, v, next;
}edge[maxn<<2];
int head[maxn];
int cnt;
void add_edge(int u, int v)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int n,m,x,y,color[maxn];
int flag;
void dfs(int u,int now){
    color[u]=now;
    if(flag)
        return;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!color[v]) dfs(v,3-now);
        else if(color[v]==now){
            flag=1;
            return;
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        add_edge(x,y);
        add_edge(y,x);
    }
    if(n==1) puts("1");
    else {
        dfs(1,1);
        if(!flag) puts("2");
        else puts("3");
    }
    return 0;
}
