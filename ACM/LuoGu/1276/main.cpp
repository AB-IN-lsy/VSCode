#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,x,y,vis[maxn],l,r,op1,ans1,ans2;
/*
vis[i]=0 本身就有树
vis[i]=1 砍完树空了
vis[i]=2 种上树苗
vis[i]=3 砍掉树苗
*/
int main()
{
    cin>>l>>n;
    for(int i=1;i<=n;i++){
        cin>>op1>>x>>y;
        if(!op1){
            for(int i=x;i<=y;i++){
                if(!vis[i]) vis[i]=1;
                else if(vis[i]==2){
                    vis[i]=3;
                    ans2++;
                }
            }
        }
        else{
            for(int i=x;i<=y;i++){
                if(vis[i]==1) vis[i]=2;
                else if(vis[i]==3) vis[i]=2;
            }
        }
    }
    for(int i=0;i<=l;i++)
    {
        if(vis[i]==2)
            ans1++;
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
