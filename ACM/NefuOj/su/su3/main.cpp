#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
int prime[N];
int b[N];
int cnt=1,max1=1e4;
int init(){//筛出素数数组
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=max1;i++){
        if(b[i])
            prime[cnt++]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=max1;j++){
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
        flag=1;
        break;
    }
    if(n==1)
        flag=1;
    return flag;
}
int main()
{
    //ios::sync_with_stdio(false);
    init();
    ll x;
    while(~scanf("%lld",&x)){
        while(x){
        if(su(x)==0){
            x=x/10;
        }
        else{
                printf("NO\n");
                break;
            }
        }
    }
    return 0;
}
