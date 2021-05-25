#include<stdio.h>
int main()
{
int i,j,k,t,n,a[5];
scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
for(i=4;i>0;i--)
{
for(j=1;j<=4;j++)
{
if(i!=j)
{
for(k=1;k<=4;k++)
{
if(k!=i&&k!=j)
{
for(t=1;t<=4;t++)
{
if(t!=k&&t!=i&&t!=j)
{
printf("%d %d %d\n",a[j],a[k],a[t]);
}
}
}
}
}
}
}
return 0;
}
