#include <bits/stdc++.h>
using namespace std;
int x2[4]={0,0,-1,1};
int y2[4]={1,-1,0,0};
struct sa
{
    int x;
    int y;
    int step;
};
queue<sa>q;
int a[1010][1010];
int n,xt,yt,xg,yg;
void bfs(int x,int y)
{
    q.push({x,y,0});
    a[x][y]=1;
    while(!q.empty()){
        sa tmp;
        tmp=q.front();
        q.pop();
        int x3=tmp.x;
        int y3=tmp.y;
        if(x3==xt&&y3==yt)
            {printf("%d\n",tmp.step);return;}
        for(int i=0;i<4;i++){
            int x4=x3+x2[i];
            int y4=y3+y2[i];
            if(x4>=1&&x4<=n&&y4>=1&&y4<=n&&a[x4][y4]==0)
            {
                q.push({x4,y4,tmp.step+1});
                a[x4][y4]=1;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    scanf("%d%d%d%d",&xg,&yg,&xt,&yt);
    bfs(xg,yg);
    return 0;
}
/*6
011111
001111
000111
010001
000001
111111
1 1 4 5*/
