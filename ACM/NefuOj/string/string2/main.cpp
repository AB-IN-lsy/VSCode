#include <bits/stdc++.h>
using namespace std;
string color,tmp,ans1;
map<string,int>vis;
map<string,int>::iterator it;
int ans,n;
int main()
{
    while(cin>>n&&n!=0){
        ans=0;
        vis.clear();
        for(int i=1;i<=n;i++){
            cin>>color;
            vis[color]++;
        }
        for(it=vis.begin();it!=vis.end();it++){
            tmp=(*it).first;
            if(ans<vis[tmp])
            {
                ans=vis[tmp];
                ans1=tmp;
            }
        }
        cout<<ans1<<endl;
    }
    return 0;
}
