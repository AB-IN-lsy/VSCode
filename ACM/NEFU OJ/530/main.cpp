#include <stdio.h>
#include <stdlib.h>
const int inf=0x3f3f3f3f;
int main()
{
    int n,i,a[105],tmp,max;
    while(scanf("%d",&n)!=-1)
    {
       tmp=0;
       max=-inf;
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);

       for(i=0;i<n;i++)
       if (max<a[i])
       {
           max=a[i];
           tmp=i;
       }
       printf("%d %d\n",max,tmp+1);

    }

    return 0;
}
