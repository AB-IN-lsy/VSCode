#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=5e5+10;
int n,m,tree[maxn];
char a[maxn],b[maxn],c;
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
int cnt,op,id,p,l,r;

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        cnt++;
        memset(tree,0,sizeof(tree));
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) {
            cin>>b[i];
            if(a[i]==b[i]) add(i,1);
        }
        printf("Case #%d:\n",cnt);
        rep(i,1,m){
            //scanf("%d",&op);
            cin>>op;
            if(!op) {
                cin>>l>>r;
                //scanf("%d%d",&l,&r);
                printf("%d\n",sum(r)-sum(l-1));
            }
            else {
                cin>>id>>p>>c;
                if(id==1){
                    if(a[p]==b[p]&&a[p]!=c) add(p,-1);
                    if(a[p]!=b[p]&&b[p]==c) add(p,1);
                    a[p]=c;
                }
                if(id==2){
                    if(a[p]==b[p]&&b[p]!=c) add(p,-1);
                    if(a[p]!=b[p]&&a[p]==c) add(p,1);
                    b[p]=c;
                }
            }
        }
    }
    return 0;
}
