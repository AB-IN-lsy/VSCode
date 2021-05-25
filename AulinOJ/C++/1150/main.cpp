#include <bits/stdc++.h>
const int N=1e3+10;
using namespace std;
typedef long long ll;
vector<ll>vis;
ll a[N];
int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
    ll tmp=0;
    for(ll l=1;l<=n;l++){
            tmp=a[l];
            vis.push_back(tmp);
            for(ll r=l+1;r<=n;r++)
            {
               tmp+=a[r];
               vis.push_back(tmp);
            }
        }
        sort(vis.begin(),vis.end());
        ll num=vis[0],s=vis.size();
        for(ll i=1;i<s;i++){
            num=num^vis[i];
        }
        cout<<num<<endl;
    return 0;
}
