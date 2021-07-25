#include <iostream>
using namespace std;
typedef long long ll;
ll n,a[100000001];
int main()
{
    cin>>n;
    a[0]=a[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2==0)
            a[i]=a[i-1]+a[i/2];
        else
            a[i]=a[i-1];
    }
    cout<<a[n];
    return 0;
}
