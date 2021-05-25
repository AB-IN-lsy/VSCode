#include <iostream>
using namespace std;
int n,x,sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        sum+=x;
    }
    cout<<sum;
    return 0;
}
