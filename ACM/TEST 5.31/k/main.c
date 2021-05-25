#include <stdio.h>
#include <stdlib.h>
int R,C,N;
int main(void)
{
   scanf("%d%d",&R,&C);
   N=R>C?R:C;
   void transfor(int a[][N]);
   int array[N][N],i,j;
   for(i=0;i<R;i++)
      for(j=0;j<C;j++)
         scanf("%d",&array[i][j]);
   transfor(array);
   for(i=0;i<C;i++)
      for(j=0;j<R;j++)
         j!=R-1?printf("%d ",array[i][j]):printf("%d\n",array[i][j]);
    return 0;
}
void transfor(int a[][N])
{
//start
int i,j,tmp;
 for(i=0,j=0;i<N;i++)
       tmp=a[i][j],a[i][j]=a[j][i],a[j][i]=tmp;
 for(i=1,j=1;i<N;i++)
       tmp=a[i][j],a[i][j]=a[j][i],a[j][i]=tmp;
       for(i=2,j=2;i<N;i++)
       tmp=a[i][j],a[i][j]=a[j][i],a[j][i]=tmp;
       for(i=3,j=3;i<N;i++)
       tmp=a[i][j],a[i][j]=a[j][i],a[j][i]=tmp;
       for(i=4,j=4;i<N;i++)
       tmp=a[i][j],a[i][j]=a[j][i],a[j][i]=tmp;
       return;
//end
}
