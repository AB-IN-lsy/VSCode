#include <bits/stdc++.h>
const int maxn=5e4+5;
int fa[3*maxn];
using namespace std;
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void join(int a,int b)
{
    int a1=find(a),b1=find(b);
    if(a1!=b1) fa[a1]=b1;
}
int n,k,ans,op1,u,v;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=3*n;i++) fa[i]=i;
    while(k--){
        cin>>op1>>u>>v;
        if(u>n||v>n) ans++;
        else if(op1==1){
            if(find(u+n)==find(v)||find(u)==find(v+n)) ans++;
            else{
                join(u,v);
                join(u+n,v+n);
                join(u+n+n,v+n+n);
            }
        }
        else{
            if(find(u)==find(v)/*°üº¬ÁËu³Ôu*/||find(v)==find(u+n)) ans++;
            else{
                join(u,v+n);
                join(u+n,v+n+n);
                join(u+n+n,v);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
