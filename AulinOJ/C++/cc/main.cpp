#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
typedef unsigned long long ll;
const ll maxn=1e3+10;
using namespace std;
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
char a[maxn][maxn];
int t,n,m;
int main(){
    t=read();
    //scanf("%d",&t);
    while(t--){
        //scanf("%d%d",&n,&m);
        n=read();m=read();
        for(int i=1;i<=n;i++){
            cin>>a[i]+1;
        }
        if(a[1][1]=='R') puts("dreagonm");
        else if(a[1][1]=='G') puts("fengxunling");
        else puts("BLUESKY007");
    }
}
