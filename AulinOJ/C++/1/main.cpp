#include <bits/stdc++.h>
typedef long long ll;
const ll maxn=2*(1e6+10);
const int mod = 1e9 + 7;
ll fac[maxn],t,n,m;
using namespace std;
ll quickmod (ll a, ll b ,ll c)
{
    ll ret=1%c;
    while(b){
        if(b&1)
            ret=ret*a%c;
        a=a*a%c;
        b=b>>1;
    }
    return ret;
}
ll inv(ll x) {
    return quickmod(x, mod-2, mod);
}
ll C(ll n,ll m){
    return fac[n]*(inv(fac[n-m])*inv(fac[m])%mod)%mod;
}
int main()
{
    fac[0]=1;
    for(int i=1;i<=maxn;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",C(n+m-2,n-1));
    }
}
