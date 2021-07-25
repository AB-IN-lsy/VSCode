#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//ll dp[1001][1001],jd[1001][1001];
map<ll,map<ll,ll> >dp;
map<int,map<int,int> >jd;
ll n,k,w1,w2,a,b;
int main()
{
    //cin>>n>>k>>w1>>w2;
    scanf("%lld%lld%lld%lld",&n,&k,&w1,&w2);
    n+=2;
    if(2*w1<w2)
    {printf("%lld",2*(n-2)*w1);return 0;}
    else{
    while(k--){
        scanf("%lld%lld",&a,&b);
        jd[a+2][b+2]=1;
    }
    for(ll i=2;i<=n;i++){
        for(ll j=2;j<=n;j++){
            if(i==2&&j==2) continue;
            if(dp[i][j]&&dp[i-1][j]&&dp[i][j-1])
                dp[i][j]=min(dp[i][j],min(dp[i-1][j]+w1,dp[i][j-1]+w1));
            else if(dp[i-1][j]&&dp[i][j-1])
                dp[i][j]=min(dp[i-1][j]+w1,dp[i][j-1]+w1);
            else if(dp[i-1][j])
                dp[i][j]=dp[i-1][j]+w1;
            else
                dp[i][j]=dp[i][j-1]+w1;

            if(jd[i-1][j-1]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+w2);
            }
        }
    }
    printf("%lld\n",dp[n][n]);
    }
    return 0;
}
