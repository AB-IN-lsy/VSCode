#include <bits/stdc++.h>
using namespace std;
int dp[21][21],n;
int main()
{
    while(cin>>n&&n!=0){
        n+=2;
        memset(dp,0,sizeof(dp));
        dp[2][2]=1;
        for(int i=2;i<=n;i++)
            for(int j=2;j<=n;j++)
             dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i][j-1]);
        cout<<dp[n][n]<<endl;
    }
    return 0;
}
