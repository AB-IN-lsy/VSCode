#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,z;
int a[100005],b[100005],sum[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>z;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<n;i++){
			b[i]=a[i]+a[i+1];
		}
		int mm=0;
		for(int i=z;i>=0;i--){
			int pos=k-2*i+1;
			if(pos<1)continue;
			int maxx=0;
			for(int j=1;j<=pos;j++){
				maxx=max(maxx,b[j]*i);
			}
			mm=max(mm,sum[pos]+maxx);
		}
		cout<<mm<<endl;
	}
	return 0;
}
