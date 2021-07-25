#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
typedef long long ll;
ll a[maxn<<2],tr[maxn<<2];
ll n,m,t,x,y,z;

inline void pushup(ll i)
{
    tr[i] = max(tr[i<<1],tr[i<<1|1]);
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
    ll res=-inf;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i];
    ll mid=(l+r)>>1;
    if(x<=mid) res=max(res,query(i<<1,l,mid,x,y));
    if(y>mid)  res=max(res,query(i<<1|1,mid+1,r,x,y));
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

char op1;
int main()
{
    cin>>n>>t;
    rep(i,1,n) cin>>a[i];
    bulid(1,1,n);
    rep(i,1,t){
        cin>>op1>>x>>y;
        if(op1=='Q'){
            cout<<query(1,1,n,x,y)<<endl;
        }
        if(op1=='U'){
            int A=query(1,1,n,x,x);
            if(A<y) update(1,1,n,x,y);
        }
    }
    return 0;
}
