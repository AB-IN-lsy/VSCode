#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) ((x) &-(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
const int mod=1e8-3;
const int maxn=1e5+10;
ll n,a[maxn],b[maxn],a_t[maxn],b_t[maxn],tree[maxn],c[maxn],pos[maxn];
ll ans;
inline void add(ll x,ll d)
{
    while(x<=n){
        tree[x]+=d;
        tree[x]%=mod;
        x+=lowbit(x);
    }
}
ll sum(ll x)
{
    ll sum=0;
    while(x>0){
        sum+=tree[x];
        sum%=mod;
        x-=lowbit(x);
    }
    return sum;
}

int main()
{
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        a_t[i]=a[i];
    }
    rep(i,1,n){
        cin>>b[i];
        b_t[i]=b[i];
    }
    sort(a_t+1,a_t+1+n);
    sort(b_t+1,b_t+1+n);
    int a_m=unique(a_t+1,a_t+1+n)-a_t-1;
    int b_m=unique(b_t+1,b_t+1+n)-b_t-1;
    rep(i,1,n){
        a[i]=lower_bound(a_t+1,a_t+1+a_m,a[i])-a_t;
        pos[a[i]] = i;
        b[i]=lower_bound(b_t+1,b_t+1+b_m,b[i])-b_t;
    }
    rep(i,1,n)
        c[i]=pos[b[i]];
    rep(i,1,n){
        add(c[i],1);
        ans=(ans+i-sum(c[i]))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
