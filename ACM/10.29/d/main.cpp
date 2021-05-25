#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10;
const int inf=0x3f3f3f3f;
struct sa{
    int dis;
    int pos;
};
bool operator <(const sa &a,const sa &b) { return a.dis>b.dis; }

priority_queue<sa>q;


struct Edge
{
    int u, v, w, next;
}edge[N<<2];
int head[N];
int cnt;
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
int n,m,s,t,u,v,w,T,k;

void dij(int s,int v,int d[]){
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) d[i] = inf;
    d[s]=v;
    q.push( (sa) {v,s});
	while(!q.empty())
	{
		sa ns=q.top();
		q.pop();
		int x=ns.pos;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x]; i!=-1 ; i=edge[i].next)
		{
			int to=edge[i].v;
			int dd=d[x]+edge[i].w;
			if(d[to]>dd)
			{
				d[to]=dd;
				q.push( (sa) {d[to],to});
			}
		}
	}
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("w.txt","w",stdout);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>k;
    for(int i = 1 ;i <= m ;i++){
        cin>>u>>v>>w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    for(int i = 1 ;i <= k; i++){
        cin>>u;
        for(int j = 1 ;j <= n; j++){
            add_edge(j, u, 0);
        }
    }
    int ans = 0;
    for(int i = 1 ;i <= n - 1; i++){
        dij(i, 0, dis);
        ans += dis[i+1];
    }
    cout<<ans;
	return 0;
}
