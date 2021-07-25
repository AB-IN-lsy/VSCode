#include <bits/stdc++.h>
using namespace std;
int dp[105][105],a[105][105];
int t,n,m;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dp[1][1]=a[1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1)
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
                else if(j==1)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
                else{
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
