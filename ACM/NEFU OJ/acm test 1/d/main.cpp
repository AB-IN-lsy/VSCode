#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    while(cin>>a[1]){
        for(int i=2;i<=10;i++){
            cin>>a[i];
        }
        sort(a+1,a+11);
        for(int i=1;i<=9;i++){
            cout<<a[i]<<" ";
        }
        cout<<a[10]<<endl;
    }
    return 0;
}
