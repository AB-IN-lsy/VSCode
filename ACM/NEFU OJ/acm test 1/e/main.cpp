#include <bits/stdc++.h>
using namespace std;
int t,a[100001],n;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n-1;i++){
            cout<<a[i]<<" ";
        }
        cout<<a[n];
        cout<<endl;
    }
    return 0;
}
