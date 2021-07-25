#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>vis;
ll l,r,k;
int main()
{
    scanf("%lld%lld",&l,&r);
    for(ll i=l;i<=r;i++){
        ll ans=log10(i)+1;
        ll tmp=i;
        for(ll j=1;j<=ans;j++){
            k=tmp%10;
            vis[k]++;
            tmp=tmp/10;
        }
    }
    for(int i=0;i<=9;i++){
        printf("%lld ",vis[i]);
    }
    return 0;
}
