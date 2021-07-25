#include <bits/stdc++.h>
#define MAX 200
using namespace std;
double f(double x)
{
    return sqrt(x*x*x-1);
}
double g(double x0,double x2_fei,double x1_fei)
{
    return (x0*x2_fei-x1_fei*x1_fei)/(x0-2*x1_fei+x2_fei);
}
double x0,eps,x1;
int k;
int main()
{
    printf("请输入初值x_0:");
    scanf("%lf",&x0);
    printf("请输入差值eps:");
    scanf("%lf",&eps);
    x1=x0;
    do{
        x0=x1;
        double x1_fei=f(x0);
        double x2_fei=f(x1_fei);
        x1=g(x0,x2_fei,x1_fei);
        k++;
        printf("第%d次迭代,此时x_%d=%.15f,x_%d=%.15f\n",k,k-1,x0,k,x1);
    }while(fabs(x1-x0)>eps&&k<MAX);
    printf("迭代终止");
    return 0;
}
