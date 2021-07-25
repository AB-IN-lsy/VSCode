#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=5e5+10;
typedef long long ll;
ll n,m,tree[maxn],a[maxn];
int vis[maxn],cnt,op;
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
ll l,r,x;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        cnt++;
        memset(tree,0,sizeof(tree));
        memset(vis,0,sizeof(vis));
        rep(i,1,n) {cin>>a[i];add(i,a[i]);}
        printf("Case #%d:\n",cnt);
        rep(i,1,m){
            cin>>op;
            if(op) {
                cin>>l>>r;
                l++;r++;
                printf("%lld\n",sum(r)-sum(l-1));
            }
            else {
                cin>>x;
                x++;
                if(vis[x]) printf("Sorry\n");
                else{
                    add(x,-a[x]);
                    vis[x]=1;
                    printf("%lld\n",a[x]);
                }
            }
        }
    }
    return 0;
}
