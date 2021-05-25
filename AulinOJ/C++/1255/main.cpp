#include <bits/stdc++.h>
using namespace std;
int x,a[10001],n;
int main()
{
    while(cin>>x&&x!=-1){
        a[++n]=x;
    }
    sort(a+1,a+n+1);
    cout<<a[n];
    return 0;
}
