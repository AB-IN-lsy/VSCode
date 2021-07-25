#include <bits/stdc++.h>
using namespace std;
int n,k;
char t[40],s[40];
int main()
{
    cin>>n>>s>>k;
    itoa(strtol(s,NULL,n),t,k);
    //to_chars(t,t+40,strtol(s,NULL,n),k);
    cout<<t;
    return 0;
}
