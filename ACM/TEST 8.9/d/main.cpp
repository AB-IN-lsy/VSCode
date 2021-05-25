#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e7+5;
ll s[]={0,2,3,2,5,7,2,3};
ll  cnt,sum,ans,prime[N],pre[N];
bool flag[N];
void init()
{
    memset(flag,1,sizeof(flag));
    flag[1]=cnt=0;
    for(ll i=2;i<=N;i++)
    {
        if(flag[i])
        {
            prime[++cnt]=i;
            pre[i]=cnt;
        }
        for(ll j=1;j<=cnt&&prime[j]*i<=N;j++)
        {
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)break;
        }
    }
}
ll n,a,b;
int main()
{
    cin>>n>>a>>b;
    init();

    return 0;
}
