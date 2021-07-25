#include <bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
ll a[10010];
ll t,n,x;
ll qm (ll a, ll b ,ll c){
    ll ret=1%c;
    while(b){
        if(b&1)
            ret=ret*a%c;
        a=a*a%c;
        b=b>>1;
    }
    return ret;
}
int main()
{
    cin>>t;
    for(int j=1;j<=t;j++){
        int f=0;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>x;
            a[x]++;
        }
        if(n&1){
            if(a[0]!=1) f=1;
            for(int i=2;i<=n-1;i+=2){
                if(a[i]!=2){
                    f=1;
                    break;
                }
            }
            if(f) cout<<"0"<<endl;
            else cout<<qm(2,(n-1)/2,mod)<<endl;
        }
        else{
            for(int i=1;i<=n-1;i+=2){
                if(a[i]!=2){
                    f=1;
                    break;
                }
            }
            if(f) cout<<"0"<<endl;
            else cout<<qm(2,(n)/2,mod)<<endl;
        }
    }
    return 0;
}
