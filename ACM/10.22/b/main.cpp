#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
char vis[1010][1010];
bool jd[1010][1010],b[1010][1010];
int n,m,ans;
struct sa
{
    int x;
    int y;
};
vector<sa> a;
vector<sa> xl;
int bfs(int x ,int y)
{
    int step=0;
    while(){
        if(vis[x][y]=='W') x=x-1;
        if(vis[x][y]=='A') y=y-1;
        if(vis[x][y]=='S') x=x+1;
        if(vis[x][y]=='D') y=y+1;

        if(b[x][y]){
            for(auto i:xl){
                if(!b[i.x][i.y]){
                    b[i.x][i.y]=1;
                    ans+=1;
                }
            }
        }
        else{
            xl.push_back({x,y});

        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 1 ;i<=n;i++){
        for( int  j= 1;j<=m;j++){
            cin>>vis[i][j];
            if( i == 1 && vis[i][j]=='W')
                a.push_back( (sa) {i,j});
            else if ( i == n && vis[i][j] == 'S')
                a.push_back( (sa) {i,j});
            else if( j == 1 && vis[i][j]=='A')
                a.push_back( (sa) {i,j});
             else if ( j == n && vis[i][j] == 'D')
                a.push_back( (sa) {i,j});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!jd[i][j]){
            }

        }
    }

}
