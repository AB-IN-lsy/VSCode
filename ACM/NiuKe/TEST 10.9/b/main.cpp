#include <bits/stdc++.h>

using namespace std;
const int mod=1e9 + 7;
string s;
int main()
{
    while(cin>>s){
        int ans=0,tmp=0;
        for(int i=s.size();i>=0;i--){
            if(s[i]=='b') tmp=(tmp+1)%mod;
            else{
                ans=(ans+tmp)%mod;
                tmp=(tmp*2)%mod;
            }
        }
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}
