#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll quickmod(ll a,ll b)
{
    int ret=1;
    while(b){
        if(b&1){
            ret=ret*a%10;
        }
        a=a*a%10;
        b=b/2;
    }
    return ret;
}
ll n,t;
int main()
{
    cin>>t;
    while(t--){
    cin>>n;
    cout<<quickmod(n,n)<<endl;
    }
    return 0;
}
