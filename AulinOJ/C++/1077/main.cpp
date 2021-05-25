#include<bits/stdc++.h>
using namespace std;
int W,ans=0;
int n,a[30010];
int l,r,i;
int main()
{
    scanf("%d%d",&W,&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    l=1;  r=n;
    while(l<=r)//要有等号。
    {
        if(a[l]+a[r]<=W)   //要有等号。
          {l++;r--;ans++;}
        else
          {r--;ans++;} //贪心过程
    }
    printf("%d\n",ans);
    return 0;
}
//写一下题解，先sort排序，然后l从头r从尾开始扫，两个加起来大了就让大的自己成组，然后继续贪心
