#include<bits/stdc++.h>
using namespace std;
bool is[505][505],vis[505];
int main()
{
    int n;
    scanf("%d",&n);
    memset(is,0,sizeof(is));
    int T=(1<<n)-1,ans=0;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        printf("<%d>",++ans);
        bool flag=0;
        for(int i=1;i<=(1<<n);i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                for(int j=i+1;j<=(1<<n);j++)
                {
                    if(!vis[j]&&!is[i][j])
                    {
                        vis[j]=1;
                        is[i][j]=1;
                        if(flag)
                            printf(",");
                        printf("%d-%d",i,j);
                        flag=1;
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
