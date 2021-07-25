#include <bits/stdc++.h>
using namespace std;
const int maxn=550;
const int inf=0x3f3f3f3f;
int w[maxn],v[maxn];
int dp[5500],sum,ans;
int main(){
       int n,W;
       cin>>n>>W;
       for(int i=1;i<=n;i++){
           cin>>w[i]>>v[i];
           sum+=v[i];
       }
       memset(dp,inf,sizeof(dp));
       dp[0]=0;
       for(int i=1;i<=n;i++){
           for(int j=sum;j>=v[i];j--){
               dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
           }
       }
       for(int i=sum;i>=0;i--){
           if(dp[i]<=W)
               {ans=i;break;}
       }
       cout<<ans<<endl;
    return 0;
}
