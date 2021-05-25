#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define rep1(i,a,n) for (int i=a;i<n;i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define per1(i,a,n) for (int i=a;i>n;i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
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

string s;
int k,i,n,g,ans;

struct sa{
    int k;
    int ans;
    int step;
};
queue<sa>q;
int main()
{
    IOS;
    cin>>n;
    cin>>s;
    n=0;
    for(int j=0;j<s.size();j++){
        if(s[j]=='k') k++;
        if(s[j]=='i') i++;
        if(s[j]=='n') n++;
        if(s[j]=='g') g++;
    }
    ans=min(g,min(i,n));
    int maxn=-inf;
    if(k>=ans) maxn=ans;
    else{
        q.push( (sa) {k,ans,0});
        while(!q.empty()){
            sa tmp=q.front();
            q.pop();
            if(tmp.k==0||tmp.ans==0){
                maxn=max(tmp.step,maxn);
                continue;
            }
            if(k>0&&ans>0) q.push((sa) {tmp.k-1,tmp.ans-1,tmp.step+1});
            if(k>0&&ans>1) q.push((sa) {tmp.k-1,tmp.ans-2,tmp.step+2});
        }
    }
    cout<<maxn<<endl;
    return 0;
}
