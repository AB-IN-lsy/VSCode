#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    while(cin>>a){
        int ans=0;
        for(int i=0;i<a.size();i++){
            ans+=a[i]-'0';
        }
    cout<<ans<<endl;
    }
    return 0;
}
