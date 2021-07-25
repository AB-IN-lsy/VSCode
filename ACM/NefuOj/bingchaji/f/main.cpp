#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=200005;

int n,m,u,v,x,y;
int k,w;
int fa[maxn];

struct sa{
    int u,v,w;
}e[maxn];

bool cmp(struct sa x,struct sa y){
    return x.w<y.w;
}

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m>>k){
            rep(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
            sort(e+1,e+1+m,cmp);
            while(k--){
                int flag=0;
                long long ans=0;
                cin>>x>>y;
                rep(i,1,n) fa[i]=i;
                rep(i,1,m){
                    w=e[i].w; u=find(e[i].u);v=find(e[i].v);
                    if(u!=v){
                        fa[u]=v;
                    }
                    if(find(x)==find(y))
                    {
                        flag=1;
                        ans=e[i].w;
                        break;
                    }
                }
                flag==1?printf("%lld\n",ans):printf("-1\n");
            }
    }
    return 0;
}
