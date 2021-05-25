#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+1;
int prime[N];
int b[N];
int cnt=1,max1=1e8;
 int init(){
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
int su(ll n){
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
    init();
    ll x;
    while(~scanf("%lld",&x)){
        if(su(x)==0)
            printf("Prime\n");
        else
            printf("Not Prime\n");
    }
    return 0;
}
