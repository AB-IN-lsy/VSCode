#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=1,num;
int main()
{
    while(cin>>n){
        ans=n*(n+1);
        ans=ans/2;
        if(ans%3==0){
            ans/=3;
            num=(ans%1007)*((2*n+1)%1007);
            num=num%1007;
        }
        else{
            num=(2*n+1)/3;
            num=num%1007;
            num=(ans%1007)*num;
            num=num%1007;
        }
        cout<<num<<endl;
    }
    return 0;
}
