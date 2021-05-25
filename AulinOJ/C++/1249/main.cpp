#include <bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    cin>>a;
    b=a;
    reverse(a.begin(),a.end());
    cout<<b+a;
    return 0;
}
