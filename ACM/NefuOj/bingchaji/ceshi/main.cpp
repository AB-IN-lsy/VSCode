#include <bits/stdc++.h>
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
    inline long long read(){
        register long long x=0,ch=gc(),w=1;
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

long long t,n,m,a,b,c;
int main()
{
    t=read();
    while(t--){
        n=read();m=read();
        if(m==1){
            a=read();
            if(n==1&&m==1&&a==1) printf("1\n");
            else printf("-1\n");
        }
        else if(m==2){
            a=read();b=read();
            if(n<m) {printf("-1\n");continue;}
            if(a==1&&b==2&&n>2) printf("1\n");
            else if(a==n-1&&b==n&&n>2) printf("%lld\n",b);
            else if(n==2&&a==1&&b==2) printf("-1\n");
            else printf("-1\n");
        }
        else if(m==3){
            a=read();b=read();c=read();
            if(n<m) {printf("-1\n");continue;}
            if(c>n) {printf("-1\n");continue;}
            if(a+1==b&&a+2==c) printf("%lld\n",b);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
