//二分+压缩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010],k,ans=0;
int n;
int main()
{
	cin>>n>>k;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];//a[i]存的是前i个数的和，这样[L,R]就可以表示为a[r]-a[l-1]
	}
	for(int i=n;i>=1;i--){
		if(a[i]-k>0){//找a[r]-a[l-1]>=k的数，换一下就是a[r]-k>=a[l-1]
                //但是1e6的数据，用o(n)会tle，所以用个logn的算法——二分
                //固定右端，判断左边，先判断差是否大于0
			int cnt=lower_bound(a+1,a+n+1,a[i]-k)-a;//返回第一个比差大于等于的数的下标
			ans+=(i-cnt);//则固定右端数 减去 到这个数的所有数都大于k，故i-cnt
		}
		else
			ans+=i;//这个数减k小于0，说明不用再分了，这个数减左边的数(即这个区间的和)都小于k，故为i
	}
	cout<<ans<<endl;
	return 0;
}
