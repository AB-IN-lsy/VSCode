#include <bits/stdc++.h>
using namespace std;
string str,tmp;
int n;
int main()
{
    cin>>n;
    while(n--){
        cin>>str;
        tmp=str;
        reverse(str.begin(),str.end());//»ØÎÄ
        if(tmp==str)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        }
    return 0;
}
