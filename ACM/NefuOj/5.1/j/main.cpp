#include <bits/stdc++.h>
using namespace std;
char str1[110][110];
int x2[]={-2,-1,0,1,2,0,0,0,0};
int y2[]={0,0,0,0,0,2,1,-1,-2};
int n,m,ans,maxn=-0x3f3f3f;
bool judge[110][110],judge1[110][110];
void dfs(int x,int y,int ans)
{
    if(x<4||x>n||y<4||y>m||judge[x][y]==true)
        return;
    for(int i=4;i<=n;i++){
        for(int j=4;j<=m;j++){
            if(i>=4&&i<=n&&j>=4&&j<=m&&judge[i][j]==false){
            for(int k=0;k<9;k++){
                int x4=i+x2[k];
                int y4=j+y2[k];
                if(str1[x4][y4]=='F')
                    judge1[x4][y4]=true;
                judge[x4][y4]=true;
            }
            dfs(i,j,ans+1);
            maxn=max(ans,maxn);
            for(int k=0;k<9;k++){
                int x4=i+x2[k];
                int y4=j+y2[k];
                if(judge1[x4][y4])
                judge[x4][y4]=false;
            }
            memset(judge1,false,sizeof(judge1));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    n+=3;m+=3;
    for(int i=4;i<=n;i++)
        for(int j=4;j<=m;j++){
          cin>>str1[i][j];
          if(str1[i][j]=='C'){
            for(int k=0;k<9;k++){
                int x4=i+x2[k];
                int y4=j+y2[k];
                judge[x4][y4]=true;
            }
          }
          if(str1[i][j]=='W'||str1[i][j]=='L')
            judge[i][j]=true;
        }
    dfs(4,4,0);
    cout<<maxn<<endl;
    return 0;
}
