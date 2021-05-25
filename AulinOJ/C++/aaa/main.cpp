#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
const ll maxn=1e6+5;
ll a[maxn];
using namespace std;
ll q (ll a, ll b)
{
    ll ret=1;
    while(b){
        if(b&1)
            ret=ret*a;
        a=a*a;
        b=b>>1;
    }
    return ret;
}
ll x;
int main()
{
    for(ll i=1;i<=maxn;i++) a[i]=q(i, 2);
    scanf("%lld",&x);
    ll ans=lower_bound(a+1, a+1+x ,x)-a;
    ll c1=a[ans]-x;
    ll c2=x-a[ans-1];
    if (c1<c2) printf("%lld\n",a[ans]);
    else printf("%lld\n",a[ans-1]);
    return 0;
}
