#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>vis[N];
int n,m,a,b;
int main()
{
   while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            vis[i].clear();//一定记得一开始清空
            vis[i].push_back(i);
        }
        while(m--){
            scanf("%d%d",&a,&b);
            if(a==b||vis[b].size()==0)
                continue;
            for(int i=0;i<vis[b].size();i++){
                    vis[a].push_back(vis[b][i]);
                }
            vis[b].clear();
            }
        for(int i=1;i<=n;i++){
            if(vis[i].size()==0)
                printf("-1\n");
            else
        {
                int ans=vis[i].size();
                for(int j=0;j<ans;j++){
                if(j==ans-1)
                printf("%d\n",vis[i][j]);
            else
                printf("%d ",vis[i][j]);
            }
        }
        }
   }
    return 0;
}
