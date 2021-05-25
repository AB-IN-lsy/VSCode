#include <bits/stdc++.h>
using namespace std;
string str,str1;
int main()
{
    cin>>str;
    str1=str;
    reverse(str.begin(),str.end());
    if(str==str1)
        cout<<"Y";
    else
        cout<<"N";
    return 0;
}
