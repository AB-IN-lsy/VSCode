#include <bits/stdc++.h>
using namespace std;
int n,x,maxn;
string s;
map<string,int>vis;
map<string,int>::iterator i;
map<int,string>v;
int main()
{
    cin>>n;
    while(n--){
        cin>>s;
        vis[s]=s.size();
        v[s.size()]=s;
    }
    for(i=vis.begin();i!=vis.end();i++){
        x=i->second;
        maxn=max(maxn,x);
    }
    cout<<v[maxn]<<endl;
    return 0;
}
