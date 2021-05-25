#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll dg(ll x)
{
    if(x==1||x==0)
        return 1;
    else
        return x*dg(x-1);
}
int main()
{
    while(scanf("%lld",&n)!=EOF){
        printf("%lld\n",dg(n));
    }
    return 0;
}
