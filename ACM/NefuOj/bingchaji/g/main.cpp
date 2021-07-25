#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
typedef long long ll;
using namespace std;
const ll maxn=2e6+10;
int n,m,u,v,cnt,w;
ll ans;
int fa[maxn];

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
    inline int read(){
        register int x=0,ch=gc(),w=1;
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





struct sa{
    int u,v,w;
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
    while(scanf("%d%d",&n,&m)!=-1){
            ans=0;cnt=0;
            rep(i,1,m) {e[i].u=read();e[i].v=read();e[i].w=read();}
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
            cnt==n-1?printf("%lld\n",ans):printf("-1\n");
    }
    return 0;
}
