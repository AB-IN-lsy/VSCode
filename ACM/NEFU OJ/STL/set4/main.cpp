#include <bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it;
int n,x,ans=1,y;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>y;
    s.insert(y);
    for(int i=1;i<=(n-1);i++)
    {
            cin>>x;
            it=s.upper_bound(x);//it��set�����е�һ������x�ĵ�����,�����ʱ��������9����Ҫ�����x=10
            if(it==s.end())//���û�б�10���������it�ͻ�ָ��s.end�������Ǹ����������ĵ�ַ
            //x��set�����е���������Ҫ�󣬽�x���룬��Ҫ��������
            {
                s.insert(x);
                ans++;
            }
            else
            //x���뵽���е������к��ʵ�λ�ã�ɾ������x�ĵ�һ����(*it)������x
            {
                s.erase(*it);
                s.insert(x);
            }
    }
    printf("%d\n",ans);
    return 0;
}
