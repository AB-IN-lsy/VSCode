#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,l,r;
ll a[1000001],sum[1000001];
inline bool check(ll mid){
	int now=0;
	int cnt=0;//计数器
	for(int i=2;i<=n;i++){
		if(sum[i]-sum[now]>mid){//如果i到now的这一段和>mid了，那么计数器+1，重新往右取区间
			cnt++;
			now=i-1;
		}
	}
	return cnt>=m;///如果最后分的区间大于等于了要分的区间，说明mid合法继续二分。
}
int main(){
    cin>>n>>m;
    cin>>a[1];
    sum[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
		l=max(l,a[i]);//最小值为整个数组最大的数（因为求的是每段最大和的最小）
	}
	r=sum[n];//右边界是前缀和的最大值（即数组的和）
	while(l<=r){///为什么用二分呢？直接遍历也是可以的，但可能会t。二分里有区间的最大值，也有不是区间的最大值，但没关系，总会找到一个最优解，满足分段且最大值最小
		ll mid=(l+r)/2;//每个mid都对应了数组一段的和
		if(check(mid))//所有的 x'(x'<x)x ′ (x ′ <x) 都是可行解。并且，如果有一个数y是非法解，那么一般的，所有的 y'(y'>y)y ′(y ′>y) 都是非法解。
			l=mid+1;
        else
            r=mid-1;
	}
	cout<<l;
	return 0;
}
