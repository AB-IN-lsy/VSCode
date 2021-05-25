#include <stdio.h>
#include <stdlib.h>
#include<string.h>
const int N=1e5+5;
int n,m;
int vis[1000005];
int a[1000005];
int main()
{
     int i,x,tmp,flag;
    while(scanf("%d%d",&n,&m)!=EOF)
     {
       flag=0;
       memset(vis,0,sizeof(vis));

        for(i=0;i<n;i++)
         {
           scanf("%d",&a[i]);
           x=a[i];
           vis[x]++;
          }
          if (m==0&&vis[0]>0)
          {
              printf("yes\n");
              continue;
          }
          if (m==0&&vis[0]==0)
          {
              printf("no\n");
              continue;
          }
         for(i=0;i<n;i++)
           if (a[i]!=0&&m%a[i]==0)
           {
           tmp=m/a[i];
           if (tmp>=1000000) continue;
           if (vis[tmp]>0&&tmp!=a[i]) flag=1;
           if (vis[tmp]>1&&tmp==a[i]) flag=1;
           }
       if (flag==1) printf("yes\n");
       else  printf("no\n");

   }


    return 0;
}

