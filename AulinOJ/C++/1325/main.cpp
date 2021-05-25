#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    while(cin>>a){
        for(int i=0;i<a.size();i++){
            a[i]=toupper(a[i]);
        }
        cout<<a<<endl;
    }
    return 0;
}
