//尺取法（滑动窗口）
#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,k,l,r,a[N];
bool judge()//用的和下面一样的变量（写在函数上面），不用在括号里定义。
{
    int tmps=0;
    for(l=1,r=1;r<=n;r++)//同向尺取判断函数
    {
        tmps+=a[r];
        while(tmps>k&&l<r)//从第二个数开始，若1，2个数加起来比k大，则把第一个吐掉，尾巴和头都在第二个数
        tmps-=a[l],
        l++;
        if(tmps==k)
        return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(judge())
        printf("%d %d\n",l,r);
    else
        printf("tiangeniupi\n");
    return 0;
}
