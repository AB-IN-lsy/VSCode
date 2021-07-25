#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],tree[maxn],m,p,k;

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
char op;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    rep(i,1,k){
        cin>>op;
        if(op=='A'){
            cin>>m;
            printf("%d\n",sum(m));
        }
        if(op=='B'){
            cin>>m>>p;
            add(m,p);
        }
        if(op=='C'){
            cin>>m>>p;
            add(m,-p);
        }
    }
    return 0;
}
