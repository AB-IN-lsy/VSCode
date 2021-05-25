#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ans;
int a[100001],n,k,l;
int main()
{
    cin>>k>>n;
    while(n){
        a[++l]=n%2;
        n/=2;
    }
    for(int i=1;i<=l;i++){
        ans+=a[i]*pow(k,i-1);
    }
    cout<<ans;
    return 0;
}
void convert (int n,int num){
    int l=0;
    while(n){
        a[++l]=n%num;
        n/=num;
    }
}
