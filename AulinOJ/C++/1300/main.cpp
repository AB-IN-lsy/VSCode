#include <bits/stdc++.h>
using namespace std;
int a[110][110],dp[110][110],t,n;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            cin>>a[i][j];
        for(int i=1;i<=n;i++)
            dp[n][i]=a[n][i];
        for(int i=n-1;i>=1;i--)
            for(int j=1;j<=i;j++)
            dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        cout<<dp[1][1]<<endl;
    }
    return 0;
}
