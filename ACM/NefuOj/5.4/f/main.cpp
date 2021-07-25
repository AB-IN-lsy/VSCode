#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int x2[4]={0,0,-1,1};
int y2[4]={1,-1,0,0};
char a[1010][1010];
bool judge[1010][1010],j;
int n,m,xt,yt,xg,yg,step;
void dfs(int x,int y,int s)
{
        judge[x][y]=true;
        if(a[x][y]=='K')
            j=true;
        if(x==xt&&y==yt&&j==true)
            {step=s;return;}
        for(int i=0;i<4;i++){
            int x4=x+x2[i];
            int y4=y+y2[i];
            if(x4>=1&&x4<=n&&y4>=1&&y4<=m&&judge[x4][y4]==false)
            {
                judge[x4][y4]=true;
                dfs(x4,y4,s+1);
                judge[x4][y4]=false;
            }
        }
        return;
    }
int main()
{
    while(scanf("%d%d",&n,&m)!=-1){
    step=-1;
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='S')
                {xg=i;yg=j;}
            if(a[i][j]=='E')
                {xt=i;yt=j;}
            if(a[i][j]=='#')
                judge[i][j]=true;
        }
    }
    dfs(xg,yg,0);
    if(j==false||step==-1)
        printf("-1\n");
    if(j==true&&step>=0)
        printf("%d\n",step);
    memset(a,0,sizeof(a));
    memset(judge,false,sizeof(judge));
    j=false;
    }
    return 0;
}
