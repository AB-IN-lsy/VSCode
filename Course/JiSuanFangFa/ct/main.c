//
//  main.c
//  Polynomial
//  秦九韶算法
//
//  Created by 庞礴 on 2020/9/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, const char * argv[]) {

    double a[1000],sum,x;
    int n;
    printf("输入多项式次数：");
    scanf("%d",&n);
    printf("\n输入自变量x：");
    scanf("%lf",&x);
    printf("\n输入n+1个系数：");
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
    printf("\n结果是：%lf\n",sum);
    clock_t end=clock();
    double t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n运行时间%lf\n",t);
    return 0;
}
