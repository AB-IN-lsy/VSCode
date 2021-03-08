/*
 * @Description: 
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-06 20:12:14
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-06 20:12:59
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll fast_mul(ll p,ll q,ll mod){      //计算p*q  
	ll ret=0;
	p%=mod; q%=mod;
	while(q>0){
		if(q&1)
		ret=(ret+p)%mod;
	
		q>>=1;
		p=(p+p)%mod;
				
	}
	return ret;
}
 
ll pow_mod(ll a,ll p,ll mod){      //计算a^p 
	ll ret=1;
	a%=mod;
	while(p>0){
		if(p&1)
		ret=fast_mul(ret,a,mod);
		
		p>>=1;
		a=fast_mul(a,a,mod);
	}
	return ret;
}
 
ll euler_phi(ll n){
	ll m=sqrt(n+0.5);
	ll ans=n;
	for(int i=2;i<=m;i++)
	if(n%i==0){
		ans=ans/i*(i-1);
		while(n%i==0) n/=i;
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
 
ll get_zhishu(ll x){
	for(int i=2;i<=x;i++){
		if(x%i==0)
		return i;
	}
}
 
int main(){
	
	ll n=1001733993063167141;
	ll d=212353;
	ll C=20190324;
	
	ll p=get_zhishu(n);
	printf("p的值为%lld\n",p);
	ll q=n/p;
	printf("q的值为%lld\n",q);
	
	ll k=(p-1)*(q-1);
	printf("k的值为%lld\n",k);
	
	ll ans=euler_phi(k);
	printf("phi(k)的值为%lld\n",ans);
	ll e=pow_mod(d,ans-1,k);
	printf("e的值为%lld\n",e);
	printf("C^e的值为%lld",pow_mod(C,e,n));	
	
} 