#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x)
{
    if(x%2==0)
        return x/2;
    else
        return 3*x+1;
}
ll x;
int main()
{
    cin>>x;
    cout<<f(x);
    return 0;
}
