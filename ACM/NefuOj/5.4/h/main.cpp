//����+ѹ��
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
		a[i]+=a[i-1];//a[i]�����ǰi�����ĺͣ�����[L,R]�Ϳ��Ա�ʾΪa[r]-a[l-1]
	}
	for(int i=n;i>=1;i--){
		if(a[i]-k>0){//��a[r]-a[l-1]>=k��������һ�¾���a[r]-k>=a[l-1]
                //����1e6�����ݣ���o(n)��tle�������ø�logn���㷨��������
                //�̶��Ҷˣ��ж���ߣ����жϲ��Ƿ����0
			int cnt=lower_bound(a+1,a+n+1,a[i]-k)-a;//���ص�һ���Ȳ���ڵ��ڵ������±�
			ans+=(i-cnt);//��̶��Ҷ��� ��ȥ ���������������������k����i-cnt
		}
		else
			ans+=i;//�������kС��0��˵�������ٷ��ˣ����������ߵ���(���������ĺ�)��С��k����Ϊi
	}
	cout<<ans<<endl;
	return 0;
}
