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

int judge;
int n,m,x,y,cnt;
map<int,int>a;
map<int,map<int,int> >b;
map<int,int>vis;
int main()
{
    //n=read();m=read();
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        //judge=read();
        cin>>judge;
        if(judge==1){
            //x=read();
            cin>>x;
            if(x>n) continue;
            if(!a[x]) {cnt++;a[x]=1;}
            if(vis[x]>0&&(!a[vis[x]])) {a[vis[x]]=1;cnt++;}
            printf("%d\n",cnt);
        }
        else if(judge==2){
            //x=read();y=read();
            cin>>x>>y;
            if(x>n||y>n) continue;
            b[x][y]=1;
            vis[x]=y;vis[y]=x;
            if(a[x]&&(!a[y])) {a[y]=1;cnt++;}
            if(a[y]&&(!a[x])) {a[x]=1;cnt++;}
            printf("%d\n",cnt);
        }
    }
    return 0;
}
