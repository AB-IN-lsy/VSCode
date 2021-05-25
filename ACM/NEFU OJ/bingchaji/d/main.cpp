#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=200005;
int n,m,u,v,cnt;
float w,ans;
int fa[maxn];

struct sa{
    int u,v;
    float w;
}e[maxn];

bool cmp(struct sa x,struct sa y){
    return x.w<y.w;
}

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n){
            ans=0.0;cnt=0;
            m=n*(n-1)/2;
            rep(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
            sort(e+1,e+1+m,cmp);
            rep(i,1,n) fa[i]=i;
            rep(i,1,m){
                if(cnt==n-1) break;
                w=e[i].w; u=find(e[i].u);v=find(e[i].v);
                if(u!=v){
                    fa[u]=v;
                    ans+=w;
                    cnt++;
                }
            }
            printf("%.2f\n",ans);
    }
    return 0;
}
