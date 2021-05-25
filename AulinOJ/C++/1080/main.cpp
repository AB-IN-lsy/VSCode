#include <bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it;
map<int,int>vis;
int main()
{
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        s.insert(x);
        vis[x]++;
    }
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<" "<<vis[*it]<<endl;
    }
    return 0;
}
