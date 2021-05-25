#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
string s,ss,ans;
int main()
{
    IOS;
    while(cin>>s)
    {
        int maxn=1;
        ss="";
        int s_z=s.size();
        for(int i=0;i<s_z/2;i++){
            ans="";
            ss+=s[i];
            int ss_z=ss.size();
            int x=s_z/ss_z;
            if(s_z%ss_z!=0) continue;
            for(int j=1;j<=x;j++) ans+=ss;
            if(ans==s) maxn=max(maxn,x);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
