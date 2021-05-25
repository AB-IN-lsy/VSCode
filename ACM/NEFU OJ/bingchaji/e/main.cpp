#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=200005;
int n,m,u,v,cnt;
int w,ans;
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
    while(cin>>n>>m&&n){
            ans=0;cnt=0;
            rep(i,1,n) cin>>e[i].u>>e[i].v>>e[i].w;
            sort(e+1,e+1+n,cmp);
            rep(i,1,m) fa[i]=i;
            rep(i,1,n){
                if(cnt==m-1) break;
                w=e[i].w; u=find(e[i].u);v=find(e[i].v);
                if(u!=v){
                    fa[u]=v;
                    ans+=w;
                    cnt++;
                }
            }
            if(cnt==m-1) cout<<ans<<endl;
            else cout<<"?"<<endl;
    }
    return 0;
}
