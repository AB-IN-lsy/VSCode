#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
int n,w,tree[2000010],x,y;
char flag;

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
int main()
{
    cin>>n>>w;
    rep(i,1,w){
        cin>>flag>>x>>y;
        if(flag=='x') add(x,y);
        else cout<<sum(y)-sum(x-1)<<endl;
    }
    return 0;
}
