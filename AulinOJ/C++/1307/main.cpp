#include <bits/stdc++.h>
using namespace std;
int x,n,b[10001],num;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        b[x]++;
    }
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(b[i]>ans){
            num=i;
            ans=b[i];
        }
    }
    cout<<num<<endl<<ans<<endl;
    return 0;
}
