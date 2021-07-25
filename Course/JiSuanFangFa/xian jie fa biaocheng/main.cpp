#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x)
{
    float f;
    f=x*x*x-x-1;
    return f;
}

int main()
{
    float x0,x1,x2,d,eps;
    int k=0;
    printf("Please input x0,x1:");
    scanf("%f%f",&x0,&x1);
     printf("Please input eps:");
     scanf("%f",&eps);
     printf("k,  xk-1   xk\n");
     printf("------------------------\n");
     printf("%d,%f,%f\n",k,x0,x1);
     do
     {
         d=-f(x1)*(x1-x0)/(f(x1)-f(x0));
         x2=x1+d;
         k++;
         x0=x1;
         x1=x2;
         printf("%d,%f,%f\n",k,x0,x1);
     }while(fabs(d)>eps);
        printf("------------------------\n");
     printf("The root of the equation is x=%f  k=%d\n",x2,k);
    return 0;
}
