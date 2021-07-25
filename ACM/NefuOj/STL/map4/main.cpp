#include <bits/stdc++.h>
using namespace std;
map<int,int>vis;
int ans;
int main()
{
    ios::sync_with_stdio(false);
    int x,n;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        vis[x]++;
        if(vis[x]==2){
            ans=ans+x;
            vis[x+1]++;
            vis[x]=0;
            vis.erase(x);
        }
    }
    int cnt=vis.size();
    printf("%d",x+1+ans-cnt);
    return 0;
}
