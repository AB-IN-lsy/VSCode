#include <bits/stdc++.h>
using namespace std;
int dp[1000001],a[1000001],n,ans;
int main()
{
    while(cin>>n){
    for(int i=1;i<=n;i++)
        cin>>a[i];
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
    return 0;
}
