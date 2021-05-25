#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,ans,flag;
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=sqrt(m*n);i++)
    {
        if((n*m)%i==0&&__gcd(i,(n*m)/i)==n)
        {
            ans++;
            if(i*i==n*m)
                flag=1;
        }
    }
    cout<<ans*2-flag;
    return 0;
}
