#include <bits/stdc++.h>
using namespace std;
unordered_map <int ,unordered_map<int,int> >a;
unordered_map <int ,unordered_map<int,int> >b;
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
int n,m,k,l,r;
using namespace IO;
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=read();
            b[i][j]=a[i][j]-a[i-1][j];
        }
    }
    k=read();
    while(k--){
        l=read();r=read();
        int flag=0;
        if(l==r) {
            puts("Yes");
            continue;
        }
        for(int j=1;j<=m;j++){
            flag=0;
            for(int i=l+1;i<=r;i++){
                //cout<<b[i][j]<<" "<<i<<" "<<j<<endl;
                if(b[i][j]<0) {
                    flag=1;
                    break;
                }
            }
            if(!flag){
                puts("Yes");
                break;
            }
        }
        if(flag) puts("No");
    }
    return 0;
}
