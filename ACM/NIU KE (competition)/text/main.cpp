#include<bits/stdc++.h>
using namespace std;

namespace IO{
    char ibuf[1<<21],*ip=ibuf,*ip_=ibuf;
    char obuf[1<<21],*op=obuf,*op_=obuf+(1<<21);
    inline char gc(){
        if(ip!=ip_)return *ip++;
        ip=ibuf;ip_=ip+fread(ibuf,1,1<<21,stdin);
        return ip==ip_?EOF:*ip++;
    }
    inline void pc(char c){
        if(op==op_)fwrite(obuf,1,1<<21,stdout),op=obuf;
        *op++=c;
    }
    inline int read(){
        register int x=0,ch=gc(),w=1;
        for(;ch<'0'||ch>'9';ch=gc())if(ch=='-')w=-1;
        for(;ch>='0'&&ch<='9';ch=gc())x=x*10+ch-48;
        return w*x;
    }
    template<class I>
    inline void write(I x){
        if(x<0)pc('-'),x=-x;
        if(x>9)write(x/10);pc(x%10+'0');
    }
    class flusher_{
    public:
        ~flusher_(){if(op!=obuf)fwrite(obuf,1,op-obuf,stdout);}
    }IO_flusher;
}
using namespace IO;


const int maxn=1e6+10;
const int inf=2147483647;
struct sa{
    int dis;
    int pos;
};
bool operator <(const sa &a,const sa &b) { return a.dis>b.dis; }

priority_queue<sa>q;


struct Edge
{
    int to, w, next;
}edge[maxn<<2];
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

void dijkstra(int s,int v,int d[]){
    memset(vis,0,sizeof(vis));
    for (int i=0;i<=n;i++) d[i] = inf;
    d[s]=v;
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
			int to=edge[i].to;
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
    memset(head,-1,sizeof(head));
	cin>>n>>m>>s;
	//n=read();m=read();s=read();
	for(int i=1; i<=m; i++){
        cin>>u>>v>>w;
		//u=read();v=read();w=read();
		add_edge(u,v,w);
	}
	dijkstra(s,0,dis);
	for(int i=1;i<=n;i++) {write(dis[i]);pc(' ');}
	return 0;
}
