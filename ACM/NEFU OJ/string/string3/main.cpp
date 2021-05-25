#include <bits/stdc++.h>
using namespace std;
string str,tmp;
int main()
{
    while(cin>>str){
        tmp=str;
        reverse(str.begin(),str.end());
        if(tmp==str)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
