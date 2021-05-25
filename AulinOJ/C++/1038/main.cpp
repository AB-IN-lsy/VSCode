#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+1;
int prime[N];
int b[N];
int cnt=1,max1=1e7;
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
int sum,a[1001],ans,flag;
int m,n,k;
int main()
{
    init();
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<(1<<n);i++){
        sum=0;
        ans=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
            {sum+=a[j];ans++;}
        }
        if(b[sum]&&ans==k)
        flag++;
    }
    printf("%d",flag);
    return 0;
}
