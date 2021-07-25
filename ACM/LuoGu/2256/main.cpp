#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;

map<string,string>fa;

string find(string  x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

string name,name1,name2,u,v;;
int n,m,t;
int main()
{
    cin>>n>>m;
    rep(i,1,n){
        cin>>name;
        fa[name]=name;
    }
    rep(i,1,m){
        cin>>name1>>name2;
        u=find(name1);v=find(name2);
        fa[u]=v;
    }
    cin>>t;
    while(t--){
        cin>>name1>>name2;
        u=find(name1);v=find(name2);
        if(u==v) cout<<"Yes."<<endl;
        else cout<<"No."<<endl;
    }
    return 0;
}
