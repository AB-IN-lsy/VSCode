#include <bits/stdc++.h>
using namespace std;
int ans,n,a[1000001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j]>a[j+1])
            {swap(a[j],a[j+1]);ans++;}
        }
    }
    cout<<ans;
    return 0;
}
