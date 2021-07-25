#include <bits/stdc++.h>
using namespace std;
int n;
double length=0xfffffff,x[20],y[20];
bool judge[100001];
double gen(int i, int k)
{
    return sqrt((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]));
}
void dfs(int k,int cnt/*¼¸²½*/,double sum)
{
    if(sum>length)
        return;
    if(cnt==n){
        length=min(length,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!judge[i]){
            double tmp=gen(i,k);
            judge[i]=true;
            dfs(i,cnt+1,sum+tmp);
            judge[i]=false;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
    x[0]=0;y[0]=0;
    dfs(0,0,0.0);
    printf("%.2lf",length);
    return 0;
}
