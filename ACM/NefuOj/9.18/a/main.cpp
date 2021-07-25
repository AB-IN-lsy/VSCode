#include <bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for (ll i=(x);i<=(y);i++)

using namespace std;
struct sa{
    ll d;
    ll judge;
};
ll n,m,l,r;
const int mod=1000000007;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
        ll ans=0;
        cin>>l>>r;
        queue<sa>q;
        q.push( (sa) {0,0});
        while(!q.empty()){
            sa tmp=q.front();
            q.pop();
            ll d=tmp.d;
            ll j=tmp.judge;
            if(d>=l && d<=r){
                ans=(ans+1)%mod;
            }
            if(d>r) continue;
            q.push( (sa) {d+1,0});
            if(!j)
            q.push( (sa) {d+m,1});
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}
