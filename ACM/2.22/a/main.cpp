#include <bits/stdc++.h>
#pragma GCC diagnostic error "-std=c++11"
using namespace std;
typedef long long ll;
map< pair<ll,ll>,int >vis;
map< pair<ll,ll>,int >::iterator it;
int main()
{
    ll n,x,y,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        ll x1=abs(x);
        ll y1=abs(y);
        vis[{x1,y1}]++;
    }
    for(it=vis.begin();it!=vis.end();it++){
        if((*it).second%2==0)
            ans+=(*it).second;
    }
    cout<<ans<<endl;
    return 0;
}
