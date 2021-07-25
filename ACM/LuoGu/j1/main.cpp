#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define endl '\n'
typedef long long ll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int maxn=2e5+10;
const double pi=acos(-1.0);

int fa[maxn],sz[maxn],col[maxn];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",col+i);
        fa[i]=i;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(col[u]==col[v])fa[find(u)]=find(v);
    }
    set<int> ans;
    int mx=0;
    for(int i=1;i<=n;i++){
        sz[find(i)]++;
        mx=max(mx,sz[find(i)]);
    }
    for(int i=1;i<=n;i++)
        if(sz[find(i)]==mx)ans.insert(i);
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
    return 0;
}
