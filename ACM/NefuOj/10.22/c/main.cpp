#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
typedef  long long ll;
const ll N=1e6+5;
ll  cnt,sum,ans,prime[N],pre[N],a[N];
bool flag[N];
using namespace std;
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
int n,m;
int main()
{
    init();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 2 ;i<= n;i++){
        if(flag[a[i]+a[1]]){
            cout<<a[i]+a[1]<<endl;
            break;
        }
    }
    return 0;
}
