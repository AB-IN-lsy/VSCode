//
//  main.c
//  Polynomial
//  �ؾ����㷨
//
//  Created by ���� on 2020/9/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, const char * argv[]) {

    double a[1000],sum,x;
    int n;
    printf("�������ʽ������");
    scanf("%d",&n);
    printf("\n�����Ա���x��");
    scanf("%lf",&x);
    printf("\n����n+1��ϵ����");
    for(int i=0;i<=n;i++)
    {
        scanf("%lf",&a[i]);
    }
    clock_t start=clock();
    sum=a[0];
    for(int i=1;i<=n;i++)
    {
        sum=sum+a[i]*pow(x, i);
    }
    printf("\n����ǣ�%lf\n",sum);
    clock_t end=clock();
    double t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n����ʱ��%lf\n",t);
    return 0;
}
