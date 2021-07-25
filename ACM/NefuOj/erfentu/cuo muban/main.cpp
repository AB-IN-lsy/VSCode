#include <bits/stdc++.h>

using namespace std;
const int N=100010;
map<int , map<int,int> > mp;
bool vis[N];
int lk[N];
int n,m,x,y,ans;

bool dfs(int x)
{
    for(int y=1;y<=n;y++){
        if(mp[x][y] && !vis[y]){
            vis[y]=1;
            if(!lk[y] || (dfs(lk[y]))){
                lk[y]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        mp[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
