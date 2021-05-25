#include <bits/stdc++.h>
#define ll long long
#define ld long double
const int N=1e3+10;
using namespace std;
ll n;
ld a[N],u[N],sum,s1,x,c;
int main()
{
    clock_t s,e;
    printf("输入多项式项数n、自变量x、系数c:\n");
    cin>>n>>x>>c;
    for(int i=0;i<=n;i++) a[i]=c;
////////////////////////////////////////////////////////////
    s=clock();
    for(int i=0;i<=n;i++){
        s1=a[i]*pow(x,i);
        sum+=s1;
    }
    printf("%.10Lf\n",sum);
    e=clock();
    printf("%.10Lf\n",(ld)(e-s)/CLOCKS_PER_SEC);
//////////////////////////////////////////////////////////
    s=clock();
    u[n]=a[n];
    for(int i=n-1;i>=0;i--) u[i]=x*u[i+1]+a[i];
    printf("%.10Lf\n",u[0]);
    e=clock();
    printf("%.10Lf\n",(ld)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
/* 100 523.6548 2321.264*/
