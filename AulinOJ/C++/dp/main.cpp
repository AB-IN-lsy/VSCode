#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,v,w,c,dp[maxn],t,ans,tmp;
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
    cin>>v>>n;ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>w>>c;
        tmp=dp[v];
        for(int j=v;j>=w;j--){
            dp[j]=max(dp[j],dp[j-w]+c);
        }
        if(dp[v]==tmp+c) ans++;
    }
    printf("%d %d\n",dp[v],ans);
    }
    return 0;
}
