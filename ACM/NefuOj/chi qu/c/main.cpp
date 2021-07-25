#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int l,r,n,len,cnt,sum,ans,prime[N],pre[N];
bool flag[N];
void init()//素数筛打表
{
    memset(flag,1,sizeof(flag));
    flag[1]=cnt=0;
    for(int i=2;i<=N;i++)
    {
        if(flag[i])
        {
            prime[++cnt]=i;
            pre[i]=cnt;//pre[i]记录i这个数是第几个素数，如果不是素数则为0
        }
        for(int j=1;j<=cnt&&prime[j]*i<=N;j++)
        {
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
    init();
    while(cin>>n&&n){
        len=lower_bound(prime+1,prime+n+1,n)-prime;
        int i=1,j=1,ans=0;
        int sum=prime[1];
        while(i<=j&&j<=len){
            if(sum>=n){
               if(sum==n) ans++;
               sum-=prime[i];
               i++;
            }
            else{
               j++;
               sum+=prime[j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
