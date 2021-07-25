#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;

ll qm (ll a, ll b ,ll c){
    ll ret = 1 % c;
    while( b ){
        if(b & 1)
            ret = ret * a % c;
        a = a * a % c;
        b = b >> 1;
    }
    return ret;
}

void solve()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    n = n % mod;
    printf("%lld\n", qm( (n * (n + 1) / 2) % mod , k, mod ));
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
