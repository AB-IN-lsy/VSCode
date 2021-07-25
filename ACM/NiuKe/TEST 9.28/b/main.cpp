#include <bits/stdc++.h>
using namespace std;
int a[1010],b[1010],vis[1010],n,ans,a1[1010],b1[1010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%1d",&a[i]);
        a1[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%1d",&b[i]);
        b1[i]=b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(a1+1,a1+n+1);
    sort(b1+1,b1+n+1);
    for(int i=1;i<=n;i++){
        int tmp=lower_bound(b+1,b+1+n,a[i])-b;
        if(tmp>=1 && tmp<=n && !vis[tmp]) {
            vis[tmp]=1;
            b[i]=-1;
            a[i]=-1;
        }
        else ans++;
    }
    memset(vis,0,sizeof(vis));
    printf("%d\n",ans);
    ans=0;
    for(int i=1;i<=n;i++){
        int tmp=upper_bound(b1+1,b1+1+n,a1[i])-b1;
        if(tmp>=1 && tmp<=n && !vis[tmp]) {
            vis[tmp]=1;
            ans++;
            b1[i]=-1;
            a1[i]=-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
