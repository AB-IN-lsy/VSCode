#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,l,r;
ll a[1000001],sum[1000001];
inline bool check(ll mid){
	int now=0;
	int cnt=0;//������
	for(int i=2;i<=n;i++){
		if(sum[i]-sum[now]>mid){//���i��now����һ�κ�>mid�ˣ���ô������+1����������ȡ����
			cnt++;
			now=i-1;
		}
	}
	return cnt>=m;///������ֵ�������ڵ�����Ҫ�ֵ����䣬˵��mid�Ϸ��������֡�
}
int main(){
    cin>>n>>m;
    cin>>a[1];
    sum[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
		l=max(l,a[i]);//��СֵΪ������������������Ϊ�����ÿ�����͵���С��
	}
	r=sum[n];//�ұ߽���ǰ׺�͵����ֵ��������ĺͣ�
	while(l<=r){///Ϊʲô�ö����أ�ֱ�ӱ���Ҳ�ǿ��Եģ������ܻ�t������������������ֵ��Ҳ�в�����������ֵ����û��ϵ���ܻ��ҵ�һ�����Ž⣬����ֶ������ֵ��С
		ll mid=(l+r)/2;//ÿ��mid����Ӧ������һ�εĺ�
		if(check(mid))//���е� x'(x'<x)x �� (x �� <x) ���ǿ��н⡣���ң������һ����y�ǷǷ��⣬��ôһ��ģ����е� y'(y'>y)y ��(y ��>y) ���ǷǷ��⡣
			l=mid+1;
        else
            r=mid-1;
	}
	cout<<l;
	return 0;
}
