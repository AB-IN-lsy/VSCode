#include <bits/stdc++.h>
using namespace std;
int n,a[1000100],b[1000100],vis[1000100],cnt;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        if(b[a[i]]==1) cnt++;
    }
    int i=1,j=1;
    int sum=1,ans=0x3f3f3f3f;
    vis[a[1]]++;
    while(i<=j&&j<=n){
        if(sum>=cnt){
            ans=min(ans,j-i+1);
            vis[a[i]]--;
            if(vis[a[i]]==0) sum--;
            i++;
        }
        else{
            j++;
            vis[a[j]]++;
            if(vis[a[j]]==1) sum++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
