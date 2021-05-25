#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll dg(ll x)
{
    if(x==1)
        return 1;
    else
        return 2*(dg(x-1)+1);
}
int main()
{
    while(cin>>n){
        cout<<dg(n)<<endl;
    }
    return 0;
}
