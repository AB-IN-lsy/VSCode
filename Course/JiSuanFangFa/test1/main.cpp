#include <bits/stdc++.h>
#define ll long long
#define ld long double
const int N=1e3+10;
using namespace std;
int n;
ld a[N],u[N],sum,s,x;
ld q (ld a, ll b){
    ld ret=1;
    while(b){
        if(b&1) ret=ret*a;
        a=a*a;
        b=b>>1;
    }
    return ret;
}
clock_t start,e;
int main()
{

    printf("�������ʽ����n���Ա���x:\n");
    cin>>n>>x;
    printf("����a_0~a_%d,��%d����:\n",n,n+1);
    for(int i=0;i<=n;i++) cin>>a[i];
///////////////////////////////////////////////////////////
    start=clock();
    for(int i=0;i<=n;i++){
        s=a[i]*pow(x,i);
        sum+=s;
    }
    printf("%Lf\n",sum);
    e=clock();
    printf("%.10Lf\n",(ld)(e-start)/CLOCKS_PER_SEC);
//////////////////////////////////////////////////////////
    start=clock();
    u[n]=a[n];
    for(int i=n-1;i>=0;i--) u[i]=x*u[i+1]+a[i];
    printf("%Lf\n",u[0]);
    e=clock();
    printf("%.10Lf\n",(ld)(e-start)/CLOCKS_PER_SEC);
    return 0;
}
/*
4 3.3
101 102 103 104 105
*/
