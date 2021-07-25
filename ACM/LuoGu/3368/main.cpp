#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
int n,m,tree[2000010],t,a,b,flag,tmp,d;

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
        add(i,t-tmp);
        tmp=t;
    }
    rep(i,1,m){
        cin>>flag;
        if(flag==1){
            cin>>a>>b>>d;
            add(a,d);
            add(b+1,-d);
        }

        if(flag==2) {cin>>a;cout<<sum(a)<<endl;}
    }
    return 0;
}
