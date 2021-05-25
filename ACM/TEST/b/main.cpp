#include <bits/stdc++.h>
using namespace std;
int t,n,inf=0x3f3f3f3f,a[10001];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double sum=0;
        int maxn=-inf,minn=inf;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            maxn=max(maxn,a[i]);
            minn=min(minn,a[i]);
        }
        printf("%d ",maxn-minn);
        double ave=sum/n,fc=0.0;
        for(int i=1;i<=n;i++){
            fc+=(a[i]-ave)*(a[i]-ave);
        }
        printf("%.3f\n",fc/n);
    }
    return 0;
}
