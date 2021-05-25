#include <bits/stdc++.h>

using namespace std;
string s;
set<string> vis;
int ans;
void dfs(string s)
{
    if(vis.find(s)!=vis.end()) return;
    vis.insert(s);
    char s1[]={s[1],s[2],s[3],s[0],s[4],s[5],0};
    dfs(s1);
    char s2[]={s[5],s[1],s[4],s[3],s[0],s[2],0};
    dfs(s2);
}
int main()
{
    cin>>s;
    sort(s.begin(),s.end());
    do
    {
        if(vis.find(s)!=vis.end()) continue;
        ans++;
        dfs(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans<<endl;
}
