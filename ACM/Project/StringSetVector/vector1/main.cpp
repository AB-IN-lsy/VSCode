#include <bits/stdc++.h>
using namespace std;
vector<int>vis;
int n,m;
int main()
{
    while(cin>>n>>m){
        vis.clear();
        int adr=0;
        for(int i=0;i<2*n;i++)
            vis.push_back(i);
        for(int i=0;i<n;i++){
            adr=(adr+m-1)%vis.size();
            vis.erase(vis.begin()+adr);
        }
        int j=0;
        for(int i=0;i<2*n;i++){
            if(j<vis.size()&&i==vis[j]){
                j++;
                cout<<"G";
            }
            else
                cout<<"B";
        }
        cout<<endl;
    }
    return 0;
}
