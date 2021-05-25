#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<x<<endl<<y<<endl;
    int m=log10(x),n=log10(y);
    if(m+1>1||n+1>1)
    {
    int x1=y%10;
    if(x*x1==0)
    {
        cout<<x*x1<<"0"<<endl;
    }
    else
    {
        cout<<x*x1<<endl;
    }
    int x2=y/10;
    cout<<x*x2<<endl;
    cout<<x*y<<endl;
    }
    else
    {
        cout<<x*y<<endl;
    }
    return 0;
}
