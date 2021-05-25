#include <bits/stdc++.h>
using namespace std;
string a;
int t;
int main()
{
    while(getline(cin,a)){
        t++;
        for(int i=0;i<a.size();i++){
            if(a[i]<=122&&a[i]>=48)
                cout<<a[i];
        }
        if(t!=4)cout<<endl;
    }
    return 0;
}
