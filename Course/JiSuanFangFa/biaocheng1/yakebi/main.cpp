#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KMAX 100
#define EPS 1e-6
float *Jacobi(float a[3][4],int n)
{
    float *x,*y,epsilon,s;
    int i,j,k=0;
    x=(float *)malloc(n*sizeof(float));
     y=(float *)malloc(n*sizeof(float));
     for(i=0;i<n;i++)
        x[i]=0;
     while(1)
     {
         epsilon=0;
         k++;
         for(i=0;i<n;i++)
         {
             s=0;
             for(j=0;j<n;j++)
             {
                 if(j==i)continue;
                 s+=a[i][j]*x[j];
             }
             y[i]=(a[i][n]-s)/a[i][i];
             epsilon=fabs(y[n-1]-x[n-1]);
         }
         if(epsilon<EPS)
         {
             printf("迭代次数为：%d\n",k);
             return y;
         }
         if(k>=KMAX)
         {
             printf("迭代方法不收敛！\n");
             return y;
         }
         for(i=0;i<n;i++)
            x[i]=y[i];
     }
}
int main()
{
    int i;
    float a[3][4]={10,-2,-1,3,
                   -2,10,-1,15,
                   -1,-2,5,10};
    float *x;
    x=Jacobi(a,3);
    for(i=0;i<3;i++)
    printf("x[%i]=%f\n",i,x[i]);

    return 0;
}
