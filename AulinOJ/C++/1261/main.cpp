#include <bits/stdc++.h>
using namespace std;
int n,a[10001][10001],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
               {cin>>a[i][j];if(i+j==n+1) ans+=a[i][j];}
    for(int i=1;i<=n;i++)
        ans+=a[i][i];
    if(n%2==1)
        cout<<ans-a[n/2+1][n/2+1];
    else
        cout<<ans;
    return 0;
}
