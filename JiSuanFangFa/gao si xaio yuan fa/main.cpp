#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
const int N=1e2+10;
double a[N][N],b[N],sum;
int n;
void SWAP(double a[N][N],int n,int x,int y){
    rep(j,1,n) swap(a[x][j],a[y][j]);
    swap(b[x],b[y]);
}
int main()
{
    printf("请输入A的阶数n:");
    scanf("%d",&n);
    printf("请输入A:\n");
    rep(i,1,n) rep(j,1,n) scanf("%lf",&a[i][j]);
    printf("请输入B:\n");
    rep(i,1,n) scanf("%lf",&b[i]);
    rep(k,1,n-1){
        per(i,n,k+1) if(fabs(a[i][k])>fabs(a[i-1][k])) SWAP(a,n,i,i-1);
        rep(i,k+1,n){
            double c=a[i][k];
            rep(j,1,n) a[i][j]-=(c/a[k][k]*a[k][j]);
            b[i]-=(c/a[k][k]*b[k]);
        }
    }
    per(k,n,1){
        sum=0.0;
        rep(j,k+1,n) sum+=(a[k][j]*b[j]);
        b[k]=(b[k]-sum)/a[k][k];
    }
    rep(i,1,n) printf("x%d=%.6f\n",i,b[i]);
    return 0;
}
/*
3
1 4 -5
1 3 -2
6 -1 18
3
2
2
*/

