#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define MAX 100
#define MIN 1e-6
using namespace std;
const int N=1e2+10;
double a[N][N],b[N],sum,x[N],x_o[N],cha;
int n,k;
int main()
{
    printf("������A�Ľ���n:");
    scanf("%d",&n);
    printf("������A:\n");
    rep(i,1,n) rep(j,1,n) scanf("%lf",&a[i][j]);
    printf("������B:\n");
    rep(i,1,n) scanf("%lf",&b[i]);
    do{
        k++;
        cha=0.0;
        rep(i,1,n){
            sum=0.0;
            rep(j,1,n) sum+=(a[i][j]*x[j]);
            x[i]+=(b[i]-sum)/a[i][i];
            cha=max(cha,fabs(x[i]-x_o[i]));
        }
        rep(i,1,n) x_o[i]=x[i];
        if(k>MAX){
            printf("����������������\n");
            return 0;
        }
    }while(cha>MIN);
    printf("��������Ϊ��%d\n",k);
    rep(i,1,n) printf("x%d=%.15f\n",i,x[i]);
    return 0;
}
/*
3
10 -2 -1
-2 10 -1
-1 -2 5
3
1.5
10
*/

/*
x1=0.635135
x2=0.510135
x3=2.331081
*/
