#include <bits/stdc++.h>
using namespace std;
int n,dp1[10001],dp2[10001],a[10001],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp1[i]=dp2[i]=1;
    }
    for(int i=2;i<=n;i++)
       for(int j=1;j<i;j++)
            if(a[j]<a[i])
                dp1[i]=max(dp1[i],dp1[j]+1);
    for(int i=n;i>=1;i--)
        for(int j=n;j>i;j--)
            if(a[i]>a[j])
                dp2[i]=max(dp2[i],dp2[j]+1);
    for(int i=1;i<=n;i++)
        ans=max(dp1[i]+dp2[i]-1,ans);
    cout<<ans;
    return 0;
}
