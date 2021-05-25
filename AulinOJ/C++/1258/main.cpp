#include <bits/stdc++.h>
using namespace std;
int a,n,sum,ans;
int main()
{
    while(cin>>a>>n){
    for(int i=0;i<n;i++){
        ans+=a*pow(10,i);
        sum+=ans;
    }
    cout<<sum;
    }
    return 0;
}
