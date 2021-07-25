#include <bits/stdc++.h>
using namespace std;
string str,tmp;
int begin1,end1;
int main()
{
    while(cin>>str){
        cin>>begin1>>end1;
        tmp=str.substr(begin1-1,end1-begin1+1);
        cout<<tmp<<endl;
    }
    return 0;
}
