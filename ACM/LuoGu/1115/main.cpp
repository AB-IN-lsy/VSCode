#include <bits/stdc++.h>
using namespace std;
int t,n,a[1000001],dp[1000001],l,r,num;
int main()
{
        cin>>n;
        int maxn=-0xfffffff;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dp[1]=a[1];
        l=1;r=1;
        for(int i=2;i<=n;i++){
            if(dp[i-1]>=0)
                dp[i]=dp[i-1]+a[i];
            else
                dp[i]=a[i];
        }
        for(int i=1;i<=n;i++){
            if(dp[i]>maxn)
            {maxn=dp[i];r=i;}
        }
        for(int i=r-1;i>=1;i--){
            if(dp[i]<0)
            {l=i+1;break;}
        }
        cout<<maxn;
    return 0;
}
