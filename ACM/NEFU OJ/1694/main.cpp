#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,x3,y3;
int mx,num[1011][1011],ans[1011];
int x2[4]={1,-1,0,0};
int y2[4]={0,0,1,-1};
void dfs(int x,int y)
{
    num[x][y]=0;
    ans[cnt]++;
    mx=max(ans[cnt],mx);
    for(int i=0;i<4;i++){
         x3=x+x2[i];
         y3=y+y2[i];
        if(x3>=0&&x3<n&&y3>=0&&y3<m&&num[x3][y3]==1)
            dfs(x3,y3);
    }
}
int main()
{

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>num[i][j];
        }
    }
    mx=cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(num[i][j]==1)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d\n",mx);
    return 0;
}
