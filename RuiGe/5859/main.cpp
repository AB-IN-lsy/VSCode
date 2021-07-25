#include <bits/stdc++.h>
using namespace std;
vector<int>vis;
int n,m;
int main()
{
    while(cin>>n>>m){
        vis.clear();
        int adr=0;
        for(int i=0;i<n;i++)
            vis.push_back(i);
        while(n>1){
            adr=(adr+m-1)%vis.size();
            vis.erase(vis.begin()+adr);
            n--;
        }
        cout<<vis[0]<<endl;
        }
    return 0;
}
