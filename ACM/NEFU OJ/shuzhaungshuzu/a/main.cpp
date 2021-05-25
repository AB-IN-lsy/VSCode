#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll n,p,x,a[maxn],tree[maxn];
ll vis[maxn];

void add(ll x,ll d)
{
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
ll sum(ll x)
{
    ll sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}

ll cnt;


int main()
{
    while(~scanf("%lld%lld",&n,&p)){
        cnt++;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        memset(tree,0,sizeof(tree));
        printf("Case #%lld:\n",cnt);
        rep(i,1,n){
            scanf("%lld",&x);
            if(!vis[x]) {
                add(i,x);
                vis[x]=1;
                a[i]=sum(i);
            }
            else{
                a[i]=a[i-1];
            }
        }
        rep(i,1,p){
            scanf("%lld",&x);
            printf("%lld\n",a[x]);
        }
    }
    return 0;

}

