#include <bits/stdc++.h>
using namespace std;
int str1[11][11];
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
    str1[x][y]=1;
    while(!q.empty()){
    sa tmp;
    tmp=q.front();
    q.pop();
    int x1=tmp.x;
    int y1=tmp.y;
    for(int i=0;i<4;i++){
        int x4=x1+x2[i];
        int y4=y1+y2[i];
        if(x4>=1&&x4<=10&&y4>=1&&y4<=10&&str1[x4][y4]==0)
        {
            q.push({x4,y4});
            str1[x4][y4]=1;
        }
    }
}
}
int main()
{
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            scanf("%d",&str1[i][j]);
        }
    }
    for(int i=1; i<=10; i++)
     {
       if(!str1[i][1]) bfs(i,1);
       if(!str1[i][10]) bfs(i,10);
       if(!str1[1][i]) bfs(1,i);
       if(!str1[10][i]) bfs(10,i);
     }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(!str1[i][j])
                ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
/*一道bfs水题，不过还是要有一点小技巧

首先，找的是不被围住的点，然后统计一下除了这些点和值为1的点，用总数减去即可。

bfs找圈外的点需要注意的是不能只从左上角开始找，有也不能只从四个角开始找，因为这四个点都可能是1，所以最完善的做法是从最外面的一周的点开始bfs，因为若这些点都是1的话，那么被围住的点就是整个图形了。

这个算法别看要多次bfs，但因为被标记的点就不会再走，所以复杂度和一个点bfs是一样的。*/
