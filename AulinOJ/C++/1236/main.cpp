#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='a'&&a[i]<='z')
            cout<<a[i];
        if(a[i]>='A'&&a[i]<='Z')
            cout<<a[i];
    }
    return 0;
}
