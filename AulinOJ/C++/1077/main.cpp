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
    while(l<=r)//Ҫ�еȺš�
    {
        if(a[l]+a[r]<=W)   //Ҫ�еȺš�
          {l++;r--;ans++;}
        else
          {r--;ans++;} //̰�Ĺ���
    }
    printf("%d\n",ans);
    return 0;
}
//дһ����⣬��sort����Ȼ��l��ͷr��β��ʼɨ���������������˾��ô���Լ����飬Ȼ�����̰��
