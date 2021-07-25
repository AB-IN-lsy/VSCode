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

int jet_num[N];
ll get_yin_zi_sum(ll n)
{
    ll ans = 1;
    for(int i = 1; (ll) prime[i] * prime[i] <= n; i++){
        if(!(n % prime[i])){
            ll jet = 1, sum = 1;
            while(!(n % prime[i])){
                jet_num[prime[i]]++;
                jet *= prime[i];
                sum += jet;
                n /= prime[i];
            }
            ans *= sum;
        }
    }
    if(n > 1) {
        jet_num[n]++;
        ans *= (n + 1);
    }
    return ans;
}

void solve()
{
    ll x;
    scanf("%lld", &x);
    printf("%lld\n", get_yin_zi_sum(x));
}


int t;
int main()
{
    init();
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
