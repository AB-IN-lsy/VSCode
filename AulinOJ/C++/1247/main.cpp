#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    getline(cin,a);
    for(int i=0;i<a.size();i++)
       a[i]=tolower(a[i]);
    cout<<a;
    return 0;
}
