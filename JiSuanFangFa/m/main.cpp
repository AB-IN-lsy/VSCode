#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,l,r,ans;
ll a[1000001],sum[1000001];
inline bool check(ll mid){
	int now=0;
	int cnt=0;//计数器
	for(int i=1;i<=n;i++){
		if(sum[i]-sum[now]>mid){//如果i到now的这一段和>mid了，那么计数器+1，重新往右取区间
			cnt++;
			now=i-1;
		}
	}
	return cnt>=m;
}
int main(){
    freopen("P1182_4.in","r",stdin);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
		l=max(l,a[i]);//最小值为整个数组最大的数（因为求的是每段最大和的最小）
	}
	r=sum[n];//右边界是前缀和的最大值（即数组的和）
	while(l<=r){
		ll mid=(l+r)/2;//每个mid都对应了数组一段的和
		if(check(mid))
		    l=mid+1;
        else
            r=mid-1;
	}
	cout<<l;
	return 0;
}
