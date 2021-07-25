#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) ((x) &-(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
const int mod=1e8-3;
const int maxn=1e5+10;
ll n,tree[maxn],c[maxn];
ll ans;

struct sa{
    ll pos;
    ll val;
}a[maxn],b[maxn];

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

bool cmp(const struct sa &a,const struct sa &b)
{
    if(a.val!=b.val) return a.val<b.val;
    else return a.pos<b.pos;
}

int main()
{
    cin>>n;
    rep(i,1,n){
        cin>>a[i].val;
        a[i].pos=i;
    }
    rep(i,1,n){
        cin>>b[i].val;
        b[i].pos=i;
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    rep(i,1,n){
        c[a[i].pos]=b[i].pos;
    }
    rep(i,1,n){
        add(c[i],1);
        ans=(ans+i-sum(c[i]))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
