#include <bits/stdc++.h>
using namespace std;
int n,t;
double tim,sum;
struct node
{
    int t;
    int num;
};
bool operator < (const node &s1,const node &s2)
{
    if(s1.t!=s2.t)return s1.t>s2.t;//��¼��ȵ��������ȵĻ�������˳���С����
    return s1.num>s2.num;
}
priority_queue<node,vector<node> >q;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        q.push({t,i});//���ʱ��Ͱ�num��ֵ��i������
    }
    while(!q.empty())
    {
        node tmp=q.top();
        q.pop();
        sum+=tim;
        tim+=tmp.t;
        if(q.empty())
            printf("%d\n",tmp.num);
        else
            printf("%d ",tmp.num);
    }
    printf("%.2lf\n",sum/n);
    return 0;
}
