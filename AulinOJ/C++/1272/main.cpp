#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2==1)
            ans+=i;
    }
    cout<<ans;
    return 0;
}
