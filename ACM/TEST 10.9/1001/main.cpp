#include <bits/stdc++.h>
#define  ll long long
using namespace std;
const int N=1e6+10;
struct sa
{
    ll x;
    ll y;
}a[N];

ll b[N];
ll t,n,m;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;i++) b[i]=i;
        for(int i=1;i<=m;i++){
            cin>>a[i].x>>a[i].y;
        }
        ll ans=0x3f3f3f3f;
        do{
            ll sum=0;
            for(int i=1;i<m;i++){
                sum+=abs(a[b[i]].x-a[b[i+1]].x);
                sum+=abs(a[b[i]].y-a[b[i+1]].y);
            }
            ans=min(sum,ans);
        }while(next_permutation(b+1,b+1+m));
        cout<<ans<<endl;
    }

    return 0;
}
