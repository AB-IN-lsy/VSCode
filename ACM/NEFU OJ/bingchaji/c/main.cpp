#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=200;
int n,counter,u,v,w,ans,cnt;

int fa[maxn];

struct sa{
    int u,v,w,judge;
}e[maxn];

bool cmp(struct sa x,struct sa y){
    if(x.judge!=y.judge) return x.judge<y.judge;
    else return x.w<y.w;
}

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        counter=0;cnt=0;ans=0;
        rep(i,1,n) fa[i]=i;
        rep(i,1,n*(n-1)/2)
        {
            cin>>e[i].u>>e[i].v>>e[i].w>>e[i].judge;
            u=find(e[i].u);v=find(e[i].v);
            if(e[i].judge && u!=v)
                {fa[find(u)]=find(v);counter++;}
        }
        sort(e+1,e+1+(n*(n-1)/2),cmp);
        rep(i,1,(n*(n-1)/2)-counter){
            if(cnt==n-1-counter) break;
            w=e[i].w; u=find(e[i].u);v=find(e[i].v);
            if(u!=v){
                fa[u]=v;
                ans+=w;
                cnt++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
