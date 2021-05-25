#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=200;
int n,m,w,ans,cnt,u,v;
char a,b;
int fa[maxn];

struct sa{
    int u,v;
    int w;
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
    while(cin>>n>>m){
        cnt=0;ans=0;
        rep(i,1,m) {cin>>a>>b; e[i].u=a-'A'+1; e[i].v=b-'A'+1; cin>>e[i].w;}
        sort(e+1,e+1+m,cmp);
        rep(i,1,n) fa[i]=i;
        rep(i,1,m){
            if(cnt==n-1) break;
            w=e[i].w; u=find(e[i].u);v=find(e[i].v);
            if(u!=v){
                fa[u]=v;
                ans+=w;
                cnt++;
            }
        }
        if(cnt==n-1) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
