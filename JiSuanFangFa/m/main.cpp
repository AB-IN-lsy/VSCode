#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,l,r,ans;
ll a[1000001],sum[1000001];
inline bool check(ll mid){
	int now=0;
	int cnt=0;//������
	for(int i=1;i<=n;i++){
		if(sum[i]-sum[now]>mid){//���i��now����һ�κ�>mid�ˣ���ô������+1����������ȡ����
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
		l=max(l,a[i]);//��СֵΪ������������������Ϊ�����ÿ�����͵���С��
	}
	r=sum[n];//�ұ߽���ǰ׺�͵����ֵ��������ĺͣ�
	while(l<=r){
		ll mid=(l+r)/2;//ÿ��mid����Ӧ������һ�εĺ�
		if(check(mid))
		    l=mid+1;
        else
            r=mid-1;
	}
	cout<<l;
	return 0;
}
