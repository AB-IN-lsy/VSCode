#include <bits/stdc++.h>
using namespace std;
int c,n,m,a[25][1010],dp[25][1010];
int main()
{
    cin>>c;
    while(c--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            cin>>a[i][j];
        dp[1][1]=a[1][1];
        for(int i=2;i<=n;i++)
            dp[i][1]=dp[i-1][1]+a[i][1];
        for(int i=2;i<=m;i++){
            dp[1][i]=dp[1][i-1]+a[1][i];
            for(int k=1;k<=i/2;k++)
                if(i%k==0)
                dp[1][i]=max(dp[1][i],dp[1][k]+a[1][i]);
        }
        for(int i=2;i<=n;i++)
        for(int j=2;j<=m;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
            dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
            for(int k=1;k<=j/2;k++)
                if(j%k==0) dp[i][j]=max(dp[i][j],dp[i][k]+a[i][j]);
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
