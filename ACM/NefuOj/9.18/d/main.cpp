#include <bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for (ll i=(x);i<=(y);i++)

using namespace std;
const int maxn=1e6+10;
ll n,m,u,v,w,ans,cnt;

ll fa[maxn];

struct sa{
    ll u,v,w;
}e[maxn];

bool cmp(struct sa x,struct sa y){
    return x.w<y.w;
}

ll find(ll x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
ll t,vis[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ans=0;
        cnt=0;
        ll mx=0,tmp=0;
        memset(e, 0, sizeof(e));
        cin>>n>>m;
        rep(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
        sort(e+1,e+1+m,cmp);
        rep(i,1,n) fa[i]=i;
        rep(i,1,m){
            if(cnt==n-1) break;
            w=e[i].w; u=find(e[i].u);v=find(e[i].v);
            if(u!=v){
                fa[u]=v;
                if(i==1) ans+=w;
                if(vis[w]) ans+=1;
                mx=max(mx,w);
                cnt++;
                vis[w]=1;
            }
        }
        cout<<max(mx,ans)<<endl;
    }
    return 0;
}
