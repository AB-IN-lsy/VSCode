#include <bits/stdc++.h>
typedef unsigned long long ll;
const ll mod=1e9+7;
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
ll factorial(ll number)
{	if(number<=1)
		return 1;
	else
		return (number*factorial(number-1)%mod);
}

ll combinator(ll n,ll m)
{	ll temp;
	if(n<m)
	{	temp=n;
		n=m;
		m=temp;}
	return (factorial(n)/(factorial(m)*factorial(n-m))%mod);
}
ll t,n;
int main()
{
    using namespace IO;
    t=read();
    while(t--){
        n=read();
        ll ans=0;
        for(ll i=1;i<=n;i++)
            ans+=i*combinator(n,i)%mod;
        write(ans%mod);
    }
    return 0;
}
