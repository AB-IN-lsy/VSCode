#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int>s;
ll l,r,maxn;
const int N=1e8+5;
int  cnt,sum,ans,prime[N],pre[N];
bool flag[N];
void init()
{
    memset(flag,1,sizeof(flag));
    flag[1]=cnt=0;
    for(int i=2;i<=N;i++)
    {
        if(flag[i])
        {
            prime[++cnt]=i;
            pre[i]=cnt;
        }
        for(int j=1;j<=cnt&&prime[j]*i<=N;j++)
        {
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)break;
        }
    }
}
ll yz(ll n)
{
        ll ans=1,len=1e8+10;
        for(int i=1;i<=len && prime[i]*prime[i]<=n;i++)
        {
            int num=0;
            while(n%prime[i]==0)
            {
                num++;
                n/=prime[i];
            }
            ans*=num+1;
            if(n==1) break;
        }
        if(n>1) ans*=2;
        return ans;
}
int main()
{
    init();
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        if(i%2==0)
        maxn=max(maxn,yz(i));
    }
    cout<<maxn;
    return 0;
}
