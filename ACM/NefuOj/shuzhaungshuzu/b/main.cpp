#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],t[maxn],tree[maxn],b[maxn],p,x;
void add(int x,int d)
{
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}
int cnt;

int main()
{
    while(~scanf("%d%d",&n,&p)){
        cnt++;
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        memset(tree,0,sizeof(tree));
        rep(i,1,n){
            scanf("%d",&a[i]);
            t[i]=a[i];
        }
        sort(t+1,t+1+n);
        int m=unique(t+1,t+1+n)-t-1;
        rep(i,1,n){
            a[i]=lower_bound(t+1,t+1+m,a[i])-t;
        }
        rep(i,1,n){
            add(a[i],1);
            b[i]=sum(a[i]-1);
        }
        printf("Case #%d:\n",cnt);
        rep(i,1,p){
            scanf("%d",&x);
            printf("%d\n",b[x]);
        }
    }
    return 0;
}
