#include <bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for (ll i=(x);i<=(y);i++)
using namespace std;
const ll maxn=1e6+10;
ll n,m,u,v,w,ans,cnt,k;

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
int t;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int j=1;j<=t;j++){
        int flag=0;
        ans=0;
        cnt=0;
        memset(e,0,sizeof(e));
        cin>>n>>m>>k;
        rep(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
        sort(e+1,e+1+m,cmp);
        rep(i,1,n) fa[i]=i;
        rep(i,1,m){
            if(cnt==n-k) {
                flag=1;
                printf("Case #%d: %lld\n",j,ans);
                break;
            }
            w=e[i].w; u=find(e[i].u);v=find(e[i].v);
            if(u!=v){
                fa[u]=v;
                ans+=w;
                cnt++;
            }
            if(cnt==n-k) {
                flag=1;
                printf("Case #%d: %lld\n",j,ans);
                break;
            }
        }
        if(!flag) printf("Case #%d: QAQ\n",j);
    }
    return 0;
}
