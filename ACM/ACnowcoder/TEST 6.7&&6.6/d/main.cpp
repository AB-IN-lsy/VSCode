#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;

int a[1005],dp[1005][2];

int main()
{
    int T,n,i;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[1][0]=0;
        dp[1][1]=a[1];
        for(i=2;i<=n;i++)
        {
            dp[i][1]=dp[i-1][0]+a[i];
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }
        printf("%d\n",max(dp[n][0],dp[n][1]));
    }
}
