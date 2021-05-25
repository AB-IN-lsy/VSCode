#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,x,y) for (ll i=(x);i<=(y);i++)
using namespace std;

struct sa{
    ll x,y,t;
}a[100005];

int fa[100005];

ll find(ll x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

ll cmp(struct sa &a,struct sa &b){
     return a.t<b.t;
}

ll n,m,u,v;
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
    n=read();m=read();
    rep(i,1,m) a[i].x=read(),a[i].y=read(),a[i].t=read();
    rep(i,1,n) fa[i]=i;
    sort(a+1,a+1+n,cmp);
    rep(i,1,m){
        u=find(a[i].x);
        v=find(a[i].y);
        if(u!=v) fa[u]=v,n--;
        if(n==1) {cout<<a[i].t<<endl;return 0;}
    }
    cout<<"-1"<<endl;
    return 0;
}
