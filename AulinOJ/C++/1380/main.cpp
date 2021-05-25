#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    while(cin>>a){
    for(int i=0;i<a.size();i++){
        if(a[i]=='0')
            a[i]='1';
        else
            a[i]='0';
    }
    cout<<a<<endl;
    }
    return 0;
}
