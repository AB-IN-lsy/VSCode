#include <bits/stdc++.h>
using namespace std;
int n,high=100;
double ans;
int main()
{
    cin>>n;
    if(n==1)
        cout<<"100.000000";
    else{
    high=ans=100;
    for(int i=2;i<=n;i++){
        ans=ans+high;
        high/=2;
    }
    printf("%.6llf",ans);
    }
    return 0;
}
