#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
typedef long long ll;
ll a[maxn<<2],tr[maxn<<2];
ll n,m,t,op1,x,y,z;

inline void pushup(ll i)
{
    tr[i] = min(tr[i<<1],tr[i<<1|1]);
}

void bulid(ll i,ll l,ll r)
{
    if(l==r){
        tr[i]=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    bulid(i<<1,l,mid);
    bulid(i<<1|1,mid+1,r);
    pushup(i);
}

inline void update (ll i,ll l,ll r,ll x,ll y)
{
    if(l>x||r<x) return;
    if(l==x&&l==r) {tr[i]=y;return;}
    ll mid=(l+r)>>1;
    update(i<<1,l,mid,x,y);
    update(i<<1|1,mid+1,r,x,y);
    pushup(i);
}

ll query(ll i,ll l,ll r,ll x,ll y)
{
    ll res=inf;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i];
    ll mid=(l+r)>>1;
    if(x<=mid) res=min(res,query(i<<1,l,mid,x,y));
    if(y>mid)  res=min(res,query(i<<1|1,mid+1,r,x,y));
    return res;
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
    n=read();t=read();
    //cin>>n>>t;
    rep(i,1,n)  a[i]=read();
      //cin>>a[i];
    bulid(1,1,n);
    rep(i,1,t){
        x=read();y=read();z=read();
        //cin>>x>>y>>z;
        if(x==1){
            update(1,1,n,y,z);
        }
        if(x==2){
            printf("%lld\n",query(1,1,n,y,z));
        }
    }
    return 0;
}
