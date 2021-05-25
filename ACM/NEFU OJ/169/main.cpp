#include <iostream>
using namespace std;
int dp[1000001],a[1000001],n,ans;
int main()
{
    while(cin>>n){
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i])
               dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
       maxn=max(maxn,dp[i]);
    }
    cout<<maxn<<endl;
}
    return 0;
}
