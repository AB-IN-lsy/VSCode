#include <bits/stdc++.h>
const int maxn=1e6+10;
using namespace std;
int a[maxn],n,x;
int main()
{
    while(cin>>n>>x){
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,less<int>());
        int ans=upper_bound(a,a+n,x)-a;
        cout<<ans<<endl;
    }
    return 0;
}
