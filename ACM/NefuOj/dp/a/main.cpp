#include <bits/stdc++.h>
using namespace std;
int dp[1000001],a[1000001],n,ans,b[1000001],tmp1,xu[1000001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i])
                if(dp[j]+1>dp[i])
                {dp[i]=max(dp[i],dp[j]+1);b[i]=j;}
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]>ans)
         {ans=dp[i];tmp1=i;}
    }
    cout<<"max="<<ans<<endl;
    int cnt=0;
    while(tmp1){
        xu[++cnt]=a[tmp1];
        tmp1=b[tmp1];
    }
    for(int i=cnt;i>=1;i--){
        cout<<xu[i]<<" ";
    }
    return 0;
}
