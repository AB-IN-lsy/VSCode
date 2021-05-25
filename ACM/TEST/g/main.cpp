#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000001];
ll yz(ll x){
	ll ans=1;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			ll temp=0;
			while(x%i==0){
				x/=i;
				temp=(temp+1)%998244353;
			}
			ans=(ans*(temp+1))%998244353;
		}
	}
	if(x>1) ans=(ans*2)%998244353;
	return ans;
}
int n,t,judge,l,r;
int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(t--){
        cin>>judge>>l>>r;
        if(judge==1){
            a[l]=r;
        }
        else{
            ll ans=1;
            for(int i=l;i<=r;i++)
                ans*=a[i];
            cout<<yz(ans)%998244353<<endl;
        }
    }
    return 0;
}
