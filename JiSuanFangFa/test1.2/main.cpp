#include <bits/stdc++.h>
#define ld long double
using namespace std;
const int N=1e3+10;
ld a[N],b[N];
int n;
int main()
{
    //从前往后
    clock_t start=clock();
    a[0]=0.1825;
    for(int i=1;i<=100;i++)
        a[i]=pow(i,-1)-5.0*a[i-1];
    printf("%.10Lf\n",a[100]);
    clock_t e=clock();
    printf("%.10Lf\n",(ld)(e-start)/CLOCKS_PER_SEC);
    ///////////////////////////////////////
    //从后往前
    /*估算I*_100的值*/
    b[100]=(pow(606,-1)+pow(505,-1))/2.0;
    start=clock();
    for(int i=100;i>0;i--)
        b[i-1]=pow(5*i,-1)-b[i]/5.0;
    printf("%.10Lf\n",b[0]);
    e=clock();
    printf("%.10Lf\n",(ld)(e-start)/CLOCKS_PER_SEC);
    return 0;
}
