#include <bits/stdc++.h>
using namespace std;
int a[100001],n,m,flag,x,y;
map<int,int>vis;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        cin>>flag>>x>>y;
        int maxn=-0xfffffff;
        int ans=0;
        vis.clear();
        if(flag==0){
            for(int i=x;i<=y;i++){
                vis[a[i]]++;
                if(vis[a[i]]>maxn){
                    maxn=vis[a[i]];
                    ans=a[i];
                }
                if(vis[a[i]]==maxn){
                    if(ans>a[i])
                        ans=a[i];
                }
            }
            cout<<ans<<endl;
        }
        if(flag==1){
            a[x]=y;
        }
    }
    return 0;
}
