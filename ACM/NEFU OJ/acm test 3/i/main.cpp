#include <bits/stdc++.h>
using namespace std;
int m,n,a[210],b[210];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        b[i]=a[i]-a[i-1]-1;
    }
    sort(b+1,b+m+1,greater<int>());
    for(int i=1;i<=n-1;i++){
        a[m]-=b[i];
    }
    cout<<a[m]<<endl;
    return 0;
}
