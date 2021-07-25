#include <bits/stdc++.h>
#define ll long long
const int N=1e6+5;
int  cnt,prime[N],pre[N];
bool flag[N];

using namespace std;

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

ll get_yin_zi_num(ll n)
{
    ll ans = 1;
    for(int i = 1; (ll) prime[i] * prime[i] <= n; i++){
        if(!(n % prime[i])){
            ll  sum = 0;
            while(!(n % prime[i])){
                sum ++;
                n /= prime[i];
            }
            ans *= (1 + sum);
        }
    }
    if(n > 1) {
        ans *= 2;
    }
    return ans;
}
int t,mod;

void solve()
{
    ll x;
    scanf("%lld", &x);
    printf("%lld\n", get_yin_zi_num(x - 1) % mod);
}



int main()
{
    init();
    scanf("%d%d", &t, &mod);
    while(t--){
        solve();
    }
    return 0;
}
