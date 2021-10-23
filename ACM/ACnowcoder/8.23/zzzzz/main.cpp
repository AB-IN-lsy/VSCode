#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define rint register int
#define ld long double
#define db double
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define rep1(i,a,n) for (rint i=a;i<n;i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define per1(i,a,n) for (rint i=a;i>n;i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define sd(x) scanf("%d",&(x))
#define slld(x) scanf("%lld",&(x))
#define sdd(x,y) scanf("%d%d",&(x),&(y))
#define sc(s) scanf("%s",(s))
#define pd(x) printf("%d\n",(x))
#define plld(x) printf("%lld\n",(x))
#define pdk(x) printf("%d ",(x))
const int inf=0x3f3f3f3f;

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
int a[10000],vis[10000],n;
int main()
{
	//n=read();
	cin>>n;
    rep(i, 1, n) cin>>a[i];//a[i]=read();
    int i=1,j=1,sum=0,ans=0;


    /*
    6
    1 2 2 3 3 1
    */
    cout<<ans<<endl;
	return 0;
}
