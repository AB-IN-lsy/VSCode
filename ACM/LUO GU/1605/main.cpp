#include <bits/stdc++.h>
using namespace std;
int x2[4]={-1,1,0,0};
int y2[4]={0,0,1,-1};
bool vis[10][10];
int n,m,t,sx,sy,fx,fy,tx,ty,ans;
void dfs(int x,int y)
{
    vis[x][y]=true;
    if(x==fx&&y==fy){
        ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int x3=x+x2[i];
        int y3=y+y2[i];
        if(x3>=1&&x3<=n&&y3>=1&&y3<=m&&vis[x3][y3]==false){
            dfs(x3,y3);
            vis[x3][y3]=false;
        }

    }
}

int main()
{
    cin>>n>>m>>t>>sx>>sy>>fx>>fy;
    for(int i=1;i<=t;i++){
        cin>>tx>>ty;
        vis[tx][ty]=true;
    }
    dfs(sx,sy);
    cout<<ans;
    return 0;
}
