#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    cin>>n>>k;
    int ans1=k-1;int ans2=1;int tmp=0;
    for(int i=2;i<=n;i++){
        tmp=ans1;
        ans1=(k-1)*(ans1+ans2);
        ans2=tmp;
    }
    cout<<ans1<<endl;
    return 0;
}
