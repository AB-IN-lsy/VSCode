#include <bits/stdc++.h>
using namespace std;

struct stu
{
    int x,y,num,sum;
}a[100];

int cmp(const stu &a,const stu &b)
{
    if(a.sum!=b.sum)
        {return a.sum>b.sum;}
    else
        {return a.num<b.num;}
}
int main()
{
    int x,y;
    for(int i=0;i<7;i++){
        cin>>x>>y;
        a[i].x=x;
        a[i].y=y;
        a[i].sum=x+y;
        a[i].num=i;
    }
    sort(a,a+7,cmp);
    if(a[0].sum>=8)
        cout<<a[0].num+1<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}
