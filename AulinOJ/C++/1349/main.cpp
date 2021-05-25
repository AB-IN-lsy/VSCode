#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int>s;
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
ll l,r,maxn;
int main()
{
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        if(i%2==0)
        maxn=max(maxn,yz(i));
    }
    cout<<maxn;
}
