#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[101],x;
int main()
{
    //freopen("write.txt","w",stdout);
    cin>>t;
    while(t--){
        int flag=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]&&a[i]!=a[i-1]+1){
                cout<<"NO\n";
                flag=1;
                break;
            }
        }
        if(!flag) cout<<"YES\n";
    }
    return 0;
}
