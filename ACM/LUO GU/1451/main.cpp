#include <bits/stdc++.h>
using namespace std;
int str1[110][110];
int x2[4]={1,-1,0,0};
int y2[4]={0,0,1,-1};
int n,m,ans;
struct sa
{
    int x;
    int y;
};
queue<sa>q;
void bfs(int x,int y)
{
    q.push({x,y});
    while(!q.empty()){
    sa tmp;
    tmp=q.front();
    q.pop();
    int x1=tmp.x;
    int y1=tmp.y;
    for(int i=0;i<4;i++){
        int x4=x1+x2[i];
        int y4=y1+y2[i];
        if(x4>=1&&x4<=n&&y4>=1&&y4<=m&&str1[x4][y4]!=0)
        {
            q.push({x4,y4});
            str1[x4][y4]=0;
        }
    }
}
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&str1[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i][j])
                bfs(i,j),ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
