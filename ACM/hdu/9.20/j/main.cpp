#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e6+10;
int n,m,u,v,x,y,ans,cnt1,cnt2,ans1,ans2;

int fa1[N],fa2[N],vis[N];

struct sa{
    int u,v;
}e1[N],e2[N];

int find1(int x) {
    if(fa1[x] == x) return x;
    return fa1[x] = find1(fa1[x]);
}
int find2(int x) {
    if(fa2[x] == x) return x;
    return fa2[x] = find2(fa2[x]);
}
set<int>s1;
set<int>s2;
set<int>s;
int main()
{
    IOS;
    freopen("read.txt","r",stdin);
    freopen("write.txt","w",stdout);
    cin>>n;
    rep(i, 1, n) cin>>vis[i];
    rep(i, 1, n-1) {
        cin>>x>>y;
        if(vis[x]&&vis[y]){
            cnt1++;
            e1[cnt1].u=x;
            e1[cnt1].v=y;
        }
        if((!vis[x])&&(!vis[y])){
            cnt2++;
            e2[cnt2].u=x;
            e2[cnt2].v=y;
        }
    }
    rep(i, 1, n) fa1[i]=i;
    rep(i, 1, n) fa2[i]=i;
    rep(i, 1, cnt1){
        u=find1(e1[i].u);v=find1(e1[i].v);
        if(u!=v){
            fa1[u]=v;
            s1.insert(u);
            s1.insert(v);
            s.insert(u);
            s.insert(v);
            ans1++;
        }
    }
    rep(i, 1, cnt2){
        u=find2(e2[i].u);v=find2(e2[i].v);
        if(u!=v){
            fa2[u]=v;
            s2.insert(u);
            s2.insert(v);
            s.insert(u);
            s.insert(v);
            ans2++;
        }
    }
    ans1++;
    ans2++;
    if(ans1>ans2){
        cout<<ans1<<endl;
        for(auto i:s1) cout<<i<<" ";
    }
    if(ans1<ans2){
        cout<<ans2<<endl;
        for(auto i:s2) cout<<i<<" ";
    }
    if(ans1==ans2){
        cout<<s.size()<<endl;
        for(auto i:s) cout<<i<<" ";
    }
    return 0;
}
