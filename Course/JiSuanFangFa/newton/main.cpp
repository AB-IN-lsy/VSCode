#include <bits/stdc++.h>
using namespace std;
double f(double x){
    return x*x*x-x*x-1;
}
double f_1(double x){
    return 3*x*x-2*x;
}
double f_2(double x){
    return 6*x-2;
}
double x0,eps,x1;
int k;
bool judge(double x)
{
    return f_1(x)*f_1(x) > fabs(f_2(x)/2) * fabs(f(x));
}
int main()
{
    label:
    printf("�������ֵx_0:");
    scanf("%lf",&x0);
    if(!judge(x0)){
        printf("��ֵx_0����������,����������\n");
        goto label;
    }
    printf("�������ֵeps:");
    scanf("%lf",&eps);
    x1=x0;
    do{
        x0=x1;
        x1=x0-(f(x0)/f_1(x0));
        k++;
        printf("��%d�ε���,��ʱx_%d=%.15f,x_%d=%.15f\n",k,k-1,x0,k,x1);
    }while(fabs(x1-x0)>eps);
    printf("������ֹ");
    return 0;
}
