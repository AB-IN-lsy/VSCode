#include <bits/stdc++.h>
#define MAX 100
using namespace std;
double f(double x)
{
    return x*x*x-x*x-1;
}
double x0,eps,x1,x2;
int k;
int main()
{
    printf("�������ֵx_0,x_1:");
    scanf("%lf%lf",&x0,&x1);
    printf("�������ֵeps:");
    scanf("%lf",&eps);
    x2=x1;
    do{
        x1=x2;
        x2=x1-(x1-x0)*f(x1)/(f(x1)-f(x0));
        k++;
        printf("��%d�ε���,��ʱx_%d=%.15f,x_%d=%.15f,x_%d=%.15f\n",k,k-1,x0,k,x1,k+1,x2);
        x0=x1;
    }while(fabs(x2-x1)>eps&&k<MAX);
    printf("������ֹ");
    return 0;
}
