#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans, a, b, u, v;
ll fa[1005];
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
ll find(ll x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
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
int main() {
    while(true){
        n=read();m=read();
        ans=0;
        rep(i,1,n) fa[i] = i;
        rep(i,1,m) {
            a=read();b=read();
            u=find(a); v=find(b);
            fa[u]=v;
        }
        rep(i,1,n) if(find(i)==i)  ans++;
        write(ans-1);pc('\n');
    }
    return 0;
}
