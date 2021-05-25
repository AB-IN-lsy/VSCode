#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=32010;
int n,a[maxn],tree[maxn],x,y;

void add(int x,int d)
{
    while(x<=maxn){
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


int main()
{
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d%d",&x,&y);
        x++;//x,y从0开始的
        a[sum(x)]++;
        add(x,1);
    }
    rep(i,0,n-1){
        printf("%d\n",a[i]);
    }
    return 0;
}
