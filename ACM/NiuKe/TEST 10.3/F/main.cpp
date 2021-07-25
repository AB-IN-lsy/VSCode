#include <bits/stdc++.h>
const int N=1e4+10;
using namespace std;
struct sa
{
    double x;
    double y;
    double d;
    int ans;
}a[N],b[N];
int n,m;
char S[N];
int main()
{
    while(~scanf("%d%d",&n,&m) && n!=0 && m!=0){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            scanf("%s",S);
            sscanf(S,"(%lf,%lf)",&a[i].x,&a[i].y);//che
        }
        for(int i=1;i<=m;i++){
            scanf("%s",S);
            sscanf(S,"(%lf,%lf)",&b[i].x,&b[i].y);//ren
        }
        for(int i=1;i<=m;i++){
            scanf("%lf",&b[i].d);
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                double dis=sqrt((a[j].x-b[i].x)*(a[j].x-b[i].x) + (a[j].y-b[i].y)*(a[j].y-b[i].y));
                if( dis <= b[i].d)
                    b[i].ans++;
            }
        }
        for(int i=1;i<=m;i++){
            printf("%d ",b[i].ans);
        }
        printf("\n");
    }
    return 0;
}
