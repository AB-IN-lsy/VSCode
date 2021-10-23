#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=1e5+10;
int a[maxn],dp[maxn],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(a[n]>n){
        puts("-1");
    }
    else
    {
        for(int i=1;i<=n;i++){
            if(a[i]<=i)dp[i]=max(dp[i-1],dp[i-a[i]]+1);
            else dp[i]=0;
        }
        cout<<dp[n]<<endl;
    }
}
