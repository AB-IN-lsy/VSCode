#include <bits/stdc++.h>
using namespace std;
int r,c,maxn;
int a[101][101],dp[101][101];
int f(int i,int j)
{
    int mr=0,ml=0,ms=0,mx=0;
    if(dp[i][j]) return dp[i][j];
    if(j+1<=c&&a[i][j]>a[i][j+1]) mr=f(i,j+1);
    if(j-1>=1&&a[i][j]>a[i][j-1]) ml=f(i,j-1);
    if(i+1<=r&&a[i][j]>a[i+1][j]) ms=f(i+1,j);
    if(i-1>=1&&a[i][j]>a[i-1][j]) mx=f(i-1,j);
    dp[i][j]=max(max(mr,ml),max(ms,mx))+1;
    return dp[i][j];
}
int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>a[i][j];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            f(i,j);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            maxn=max(maxn,dp[i][j]);
    cout<<maxn<<endl;
    return 0;
}
