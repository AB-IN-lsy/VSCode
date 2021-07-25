#include <bits/stdc++.h>
using namespace std;
int x2[4]={0,0,-1,1};
int y2[4]={1,-1,0,0};
const int inf=0x3f3f3f;
struct sa
{
    int x;
    int y;
    int step;
};
queue<sa>q;
int a[1010][1010],dis[1010][1010];
int n;
int bfs(int x,int y)
{
    int ans=inf;
    q.push({x,y,a[x][y]});
    while(!q.empty()){
        sa tmp;
        tmp=q.front();
        q.pop();
        int x3=tmp.x;
        int y3=tmp.y;
        if(x3==n&&y3==n)
            ans=min(ans,tmp.step);
        for(int i=0;i<4;i++){
            int x4=x3+x2[i];
            int y4=y3+y2[i];
            if(x4>=1&&x4<=n&&y4>=1&&y4<=n&&a[x4][y4]!=0)
            {
                if(tmp.step+a[x4][y4]<dis[x4][y4]){
                    dis[x4][y4]=tmp.step+a[x4][y4];
                    q.push({x4,y4,tmp.step+a[x4][y4]});
                }
            }
        }
    }
    return ans;
}
int ans=inf;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            dis[i][j]=inf;
        }
    }
    if(!a[1][1]||!a[n][n])
        printf("0");
    else{
        ans=bfs(1,1);
        if(ans==inf){
            printf("0");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
