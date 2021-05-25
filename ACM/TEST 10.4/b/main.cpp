#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e8+10;
ll n,b[N],x,ans;
unordered_map <ll, ll> a;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) b[i]=b[i-1]+i-1;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[x-b[i]]++;
        ans=max(ans,a[x-b[i]]);
    }
    cout<<n-ans<<endl;
}
