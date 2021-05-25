#include <bits/stdc++.h>
using namespace std;
int a[10],t;
int main()
{
    cin>>t;
    while(t--){
        for(int i=1;i<=9;i++)
            cin>>a[i];
        for(int i=9;i>=2;i--)
            if(a[i]<a[1])
            cout<<a[i]<<" ";
        cout<<a[1]<<" ";
        for(int i=2;i<=9;i++)
            if(a[i]>a[1])
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
