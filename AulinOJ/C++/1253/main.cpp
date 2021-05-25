#include <bits/stdc++.h>
using namespace std;
string a;
int ans;
int main()
{
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='a'&&a[i]<='z')
            ans++;
        if(a[i]>='A'&&a[i]<='Z')
            ans++;
    }
    cout<<ans;
    return 0;
}
