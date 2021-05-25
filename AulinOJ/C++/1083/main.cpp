#include <bits/stdc++.h>
using namespace std;
string str;
int main()
{
    cin>>str;
    int sum=(str[0]-'0')*1+(str[2]-'0')*2+(str[3]-'0')*3+(str[4]-'0')*4+(str[6]-'0')*5+(str[7]-'0')*6+(str[8]-'0')*7+(str[9]-'0')*8+(str[10]-'0')*9;
    if(sum%11==(str[12]-'0'))
        cout<<"Right";
    else if(sum%11==10&&str[12]=='X')
        cout<<"Right";
    else{
        for(int i=0;i<=11;i++){
            cout<<str[i];
        }
        if(sum%11==10)
             cout<<'X';
        else
            cout<<sum%11;
    }
    return 0;
}
