#include <bits/stdc++.h>
using namespace std;
int x2[4]={0,0,-1,1};
int y2[4]={1,-1,0,0};
struct sa
{
    int x;
    int y;
};
queue<sa>q;
int a[1010][1010],flag[1001][1001],num[1000001];//用flag记录坐标，坐标的值是第几个连通块，连通块里每个点的步数相同
bool judge[1010][1010];//节约时间
int n,m,x4,y4,cnt;
inline void bfs(int x,int y)
{
    q.push({x,y});
    while(!q.empty()){
        sa tmp;
        tmp=q.front();
        q.pop();
        int x3=tmp.x;
        int y3=tmp.y;
        judge[x3][y3]=false;
        flag[x3][y3]=cnt;//第几个连通块
        num[flag[x3][y3]]++;//能走几步
        for(int i=0;i<4;i++){
            int x4=x3+x2[i];
            int y4=y3+y2[i];
            if(x4>=1&&x4<=n&&y4>=1&&y4<=n&&a[x4][y4]!=a[x3][y3]&&judge[x4][y4]==true)
            {
                q.push({x4,y4});
                judge[x4][y4]=false;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    memset(judge,true,sizeof(judge));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(judge[i][j]==true)
                {
                cnt++;
                bfs(i,j);
                }
    while(m--){
        scanf("%d%d",&x4,&y4);
        printf("%d\n",num[flag[x4][y4]]);
    }
    return 0;
}
