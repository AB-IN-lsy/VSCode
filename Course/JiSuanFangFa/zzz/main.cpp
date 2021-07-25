#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
struct sa{
    int dis;
    int pos;
};
bool operator <(const sa &a,const sa &b) { return a.dis>b.dis; }

priority_queue<sa>q;


struct Edge
{
    int to, w, next;
}edge[maxn];
int head[maxn];
int cnt;
void add_edge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}


int dis[maxn];
bool vis[maxn];
int n,m,s,u,v,w;

void dijkstra(int s){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push( (sa) {0,s});
	while(!q.empty())
	{
		sa ns=q.top();
		q.pop();
		int x=ns.pos;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x]; i!=-1 ; i=edge[i].next)
		{
			if(dis[edge[i].to]>dis[x]+edge[i].w)
			{
				dis[edge[i].to]=dis[x]+edge[i].w;
				q.push( (sa) {dis[edge[i].to],edge[i].to});
			}
		}
	}
}
vector<int> vv;
int t,k,x;
int main()
{
    cin>>t;
    for(int j=1;j<=t;j++){
        int f=0;
        memset(head,-1,sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(vis));
        vv.clear();
        cin>>n>>m>>k;
        //n=read();m=read();s=read();
        for(int i=1; i<=m; i++){
            cin>>u>>v>>w;
            //u=read();v=read();w=read();
            add_edge(u,v,w);
            add_edge(v+n,u+n,w);
        }
        long long ans=0;
        for(int i=1;i<=k;i++){
            cin>>x;
            if(x!=1)
            vv.push_back(x);
        }
        dijkstra(1);
        for(auto i:vv){
            if(dis[i]==inf){
                printf("Case #%d: QAQ\n",j);
                f=1;
                break;
            }
            ans+=dis[i];
        }
        if(f) continue;
        dijkstra(1+n);
        for(auto i:vv){
            if(dis[i+n]==inf){
                printf("Case #%d: QAQ\n",j);
                f=1;
                break;
            }
            ans+=dis[i+n];
        }
        if(!f) printf("Case #%d: %lld\n",j,ans);
    }
	return 0;
}
