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
    if(s1.t!=s2.t)return s1.t>s2.t;//记录相等的情况，相等的话按出现顺序从小到大
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
        q.push({t,i});//这个时候就把num的值用i赋上了
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
