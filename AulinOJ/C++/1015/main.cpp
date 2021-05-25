#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int jc (ll x)
{
    ll s=1;
    for(ll i=1;i<=x;i++)
    {
        s=s*i;
    }
    return s;
}
int main()
{
    ll x,ans=0;
    cin>>x;
    for(ll i=1;i<=x;i++){
        ans=ans+jc(i);
    }
    cout<<ans<<endl;
    return 0;
}
