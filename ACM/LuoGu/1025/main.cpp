#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
void dfs(int last,int sum,int step)
{
     if(step>k)
        return;
     if (step==k){
        if (sum==n)
            ans++;
        return;
     }
     for(int i=last;sum+i*(k-step)<=n;i++)//1.��Ҫ��֤����˳�򣨲��ظ���������forѭ������С��������ҡ�
        //��֦��2.���ǵ����ģ����������i������ʱ��>n�ˣ�����������϶�������n����˼�֦
        dfs(i,sum+i,step+1);
    return;
}
int main()
{
    cin>>n>>k;
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}
