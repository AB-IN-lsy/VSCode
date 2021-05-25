#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sa
{
    ll l;
    ll r;
    ll ans;
}a[10001];
ll m,n;
int main()
{
    cin>>m;
    ll n=sqrt(m);
    ll i=1,j=1;
    ll sum=1,cnt=0;
    while(i<=j&&j<=n){
        if(sum>=m){
            if(sum==m){
                cnt++;
                a[cnt].l=i;
                a[cnt].r=j;
                a[cnt].ans=j-i+1;
            }
            sum-=i*i;
            i++;
        }
        else{
            j++;
            sum+=j*j;
        }
    }
    cout<<cnt<<endl;
    for(ll i=1;i<=cnt;i++){
        cout<<a[i].ans<<" ";
        for(ll j=a[i].l;j<=a[i].r;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
