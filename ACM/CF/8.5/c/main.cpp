#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[101],b[100000001];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        ll maxn=-0x3f;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                b[a[i]+a[j]]++;
                maxn=max(maxn,b[a[i]+a[j]]);
            }
        }
        cout<<maxn<<endl;
    }
    return 0;
}
