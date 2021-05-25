#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        int ans=3;
        for(int i=1;i<=n;i++){
            ans=(ans-1)*2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
