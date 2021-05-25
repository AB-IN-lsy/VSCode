#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1;
int prime[N];
int b[N];
int cnt=1;
 int init(){//筛出素数数组
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=N;i++){
        if(b[i])
            prime[cnt++]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=N;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }

    }
    return 0;
}
 int su(ll n){//判断是否为素数
int flag=0;
for(int i=1;prime[i]<=sqrt(n*1.0);i++)
    if(n%prime[i]==0){
        int tmp=n/prime[i];
        if(b[tmp]){
             flag=1;
             break;
        }
    }
    return flag;
}
int main()
{
    init();
    ll x;
    while(~scanf("%lld",&x)){
         if(su(x))
         {
             printf("YES\n");
         }
         else
            printf("NO\n");
    }
    return 0;
}
