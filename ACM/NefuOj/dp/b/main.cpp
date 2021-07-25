#include <bits/stdc++.h>
using namespace std;
int dp[1000001],a[1000001],n,ans;
int main()
{
    while(cin>>a[++n]);
    n--;
    for(int i=n;i>=1;i--){
        dp[i]=1;
        for(int j=i+1;j<=n;j++){
            if(a[i]>=a[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

}
