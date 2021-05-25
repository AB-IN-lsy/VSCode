#include <bits/stdc++.h>
using namespace std;
double x,ans,t,a[1001];
int n;
int main()
{
    while(cin>>n){
        ans=0.0;
        t=0.0;
        for(int i=1;i<=n;i++)
            {cin>>a[i];t++;}
        sort(a+1,a+n+1);
        for(int i=2;i<=n-1;i++)
            ans+=a[i];
        printf("%.2llf\n",ans/(t-2));
    }
    return 0;
}
