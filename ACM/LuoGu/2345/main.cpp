#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for (ll i=(x);i<=(y);i++)
const int N=2e4+10;
struct sa{
    ll v;
    ll x;
}a[N];
ll t,ans;
int main()
{
    cin>>t;
    rep(i,1,t){
        cin>>a[i].v>>a[i].x;
    }
    rep(i,1,t){
        rep(j,i+1,t){
            ans+=max(a[i].v,a[j].v)*abs(a[i].x-a[j].x);
        }
    }
    cout<<ans<<endl;
    return 0;
}
