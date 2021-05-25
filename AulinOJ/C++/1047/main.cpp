#include <bits/stdc++.h>
using namespace std;
int vis[10010];
int l,m,ans;
int main()
{
    cin>>l>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        for(int j=a;j<=b;j++){
            vis[j]=1;
        }
    }
    for(int i=0;i<=l;i++){
        if(!vis[i])
            ans++;
    }
    cout<<ans;
    return 0;
}
