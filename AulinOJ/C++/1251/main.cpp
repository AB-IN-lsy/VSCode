#include <bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
    for(int i=1;i<=4;i++)
        cin>>a[i];
    sort(a+1,a+5);
    for(int i=1;i<=4;i++)
        cout<<a[i]<<" ";
    return 0;
}
