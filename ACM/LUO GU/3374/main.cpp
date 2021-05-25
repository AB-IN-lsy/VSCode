#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
int n,m,tree[2000010],t,a,b,flag;

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
    cin>>n>>m;
    rep(i,1,n){
        cin>>t;
        add(i,t);
    }
    rep(i,1,m){
        cin>>flag>>a>>b;
        if(flag==1) add(a,b);
        if(flag==2) cout<<sum(b)-sum(a-1)<<endl;
    }
    return 0;
}
