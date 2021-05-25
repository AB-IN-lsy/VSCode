#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
typedef  long long ll;
const ll N=1e7+5;
ll  cnt,sum,ans,prime[N],pre[N],v[N];
bool flag[N];
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
void init()
{
    memset(flag,1,sizeof(flag));
    flag[1]=cnt=0;
    for(ll i=2;i<=N;i++)
    {
        if(flag[i])
        {
            prime[++cnt]=i;
            pre[i]=cnt;
        }
        for(ll j=1;j<=cnt&&prime[j]*i<=N;j++)
        {
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)break;
        }
    }
}
ll t,a,b;
int main()
{
    init();
    cin>>t;
    for(ll i=2;i<=N;i++)//这里变成了N
        v[i]=v[i-1]+flag[i];
    while(t--){
        cin>>a>>b;

    }
}
