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
/*һ��bfsˮ�⣬��������Ҫ��һ��С����

���ȣ��ҵ��ǲ���Χס�ĵ㣬Ȼ��ͳ��һ�³�����Щ���ֵΪ1�ĵ㣬��������ȥ���ɡ�

bfs��Ȧ��ĵ���Ҫע����ǲ���ֻ�����Ͻǿ�ʼ�ң���Ҳ����ֻ���ĸ��ǿ�ʼ�ң���Ϊ���ĸ��㶼������1�����������Ƶ������Ǵ��������һ�ܵĵ㿪ʼbfs����Ϊ����Щ�㶼��1�Ļ�����ô��Χס�ĵ��������ͼ���ˡ�

����㷨��Ҫ���bfs������Ϊ����ǵĵ�Ͳ������ߣ����Ը��ӶȺ�һ����bfs��һ���ġ�*/
