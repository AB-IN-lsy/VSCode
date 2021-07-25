#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],dp[1001][1001],ans,n,m;
int main()
{
    while(cin>>n>>m){
    ans=-0xfffffff;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]){
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<endl;
}
    return 0;
}
