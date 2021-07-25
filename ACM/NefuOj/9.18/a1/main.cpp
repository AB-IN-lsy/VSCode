#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N=1e5+10;
using namespace std;
const int mod=1000000007;
ll dp[N][2],sum[N],l,r,n,m;
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
    for(int i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(int i=m;i<=N;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=(dp[i-m][0])%mod;
    }
    for(int i=1;i<=N;i++){
        sum[i]=(sum[i-1]+dp[i][0]+dp[i][1])%mod;
    }
    for(int i=1;i<=n;i++){
        l=read();r=read();
        write((ll)(sum[r]-sum[l-1]+mod)%mod);
        pc('\n');
    }
    return 0;
}
