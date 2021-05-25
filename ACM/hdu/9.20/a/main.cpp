#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++){
        int ans=0;
        unordered_map<char,int>m;
        cin>>s;
        for(char j:s) {
            m[j]++;
            ans=max(ans,m[j]);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
