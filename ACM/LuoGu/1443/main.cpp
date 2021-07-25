#include <bits/stdc++.h>
using namespace std;
int x2[8]={-1,1,-1,1,2,2,-2,-2};
int y2[8]={2,2,-2,-2,-1,1,-1,1};
int n,m,x3,y3,ans;
int a[410][410];
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
    for(int i=0;i<8;i++){
        int x4=x1+x2[i];
        int y4=y1+y2[i];
        if(x4>=1&&x4<=n&&y4>=1&&y4<=m&&a[x4][y4]==-1)
        q.push({x4,y4}),a[x4][y4]=a[x1][y1]+1;
    }
}

}
int main()
{
    scanf("%d%d%d%d",&n,&m,&x3,&y3);
    memset(a,-1,sizeof(a));
    a[x3][y3]=0;
    bfs(x3,y3);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
