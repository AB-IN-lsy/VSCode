#include <bits/stdc++.h>
using namespace std;
double ans;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        ans+=1/i;
    printf("%.6llf",ans);
    return 0;
}
