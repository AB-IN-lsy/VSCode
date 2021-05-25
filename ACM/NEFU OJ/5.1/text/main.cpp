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
				temp=(temp+1);
			}
			ans=(ans*(temp+1));
		}
	}
	if(x>1) ans=(ans*2);
	return ans;
}
int t,p;
ll x;
int main()
{
    cin>>t>>p;
    while(t--){
        cin>>x;
        cout<<yz(x-1)%p<<endl;
    }
    return 0;
}
