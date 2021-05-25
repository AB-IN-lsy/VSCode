#include <bits/stdc++.h>
using namespace std;
int t,n,a[1001];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        int pd=1;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        int d=a[2]-a[1];
        for(int i=3;i<=n;i++){
            int b=a[i-1]+d;
            if(b!=a[i])
            {pd=0;cout<<"no"<<endl;break;}
        }
        if(pd)
            cout<<"yes"<<endl;
    }
    return 0;
}
