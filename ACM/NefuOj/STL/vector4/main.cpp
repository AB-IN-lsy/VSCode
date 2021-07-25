#include <bits/stdc++.h>
using namespace std;
vector<int>vis[50];
int n,m,a,b;
int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            vis[i].push_back(i);
        }
        while(m--){
            scanf("%d%d",&a,&b);
            if(a==b)
                continue;
            else{
                int ans=vis[b].size();
                for(int i=0;i<ans;i++){
                    vis[a].push_back(vis[b][i]);
                    vis[b].erase(vis[b].begin());
                }
            }
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
            vis[i].clear();
        }
        }
    }
    return 0;
}
