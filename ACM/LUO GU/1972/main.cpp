#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) ((x) &-(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
const int maxn=1e6+10;
int vis[maxn];
ll tree[maxn],a[maxn],id[maxn],ans[maxn];
ll n,m,l,r;
inline void add(ll x,ll d)
{
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
ll sum(ll x)
{
    ll sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}
struct sa{
    int l;
    int r;
    int pos;
}q[maxn];

bool cmp(const struct sa &a,const struct sa &b)
{
    return a.r<b.r;
}

namespace IO{
    char ibuf[1<<21],*ip=ibuf,*ip_=ibuf;
    char obuf[1<<21],*op=obuf,*op_=obuf+(1<<21);
    inline char gc(){
        if(ip!=ip_)return *ip++;
        ip=ibuf;ip_=ip+fread(ibuf,1,1<<21,stdin);
        return ip==ip_?EOF:*ip++;
    }
    inline void pc(char c){
        if(op==op_)fwrite(obuf,1,1<<21,stdout),op=obuf;
        *op++=c;
    }
    inline ll read(){
        register ll x=0,ch=gc(),w=1;
        for(;ch<'0'||ch>'9';ch=gc())if(ch=='-')w=-1;
        for(;ch>='0'&&ch<='9';ch=gc())x=x*10+ch-48;
        return w*x;
    }
    template<class I>
    inline void write(I x){
        if(x<0)pc('-'),x=-x;
        if(x>9)write(x/10);pc(x%10+'0');
    }
    class flusher_{
    public:
        ~flusher_(){if(op!=obuf)fwrite(obuf,1,op-obuf,stdout);}
    }IO_flusher;
}
using namespace IO;


int main()
{
    n=read();
    rep(i,1,n){
        a[i]=read();
    }
    m=read();
    rep(i,1,m){
        q[i].l=read();q[i].r=read();
        q[i].pos=i;
    }
    sort(q+1,q+1+m,cmp);
    int tmp=1;
    rep(i,1,m){
        rep(j,tmp,q[i].r){
            if(vis[a[j]])
                add(id[a[j]],-1);
            add(j,1);
            id[a[j]]=j;
            vis[a[j]]=1;
        }
        tmp=q[i].r+1;
        ans[q[i].pos]= sum(q[i].r)-sum(q[i].l-1);
    }
    rep(i,1,m){
        write(ans[i]);
        pc('\n');
    }
    return 0;
}
