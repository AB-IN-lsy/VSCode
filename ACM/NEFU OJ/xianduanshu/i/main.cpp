#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll a[maxn<<2],tr[maxn<<2],add_tag[maxn<<2];
//  原数组     线段树      加法lazy_tag标记
ll n,m,p,op1,x,y,k;

inline void pushup(ll i)//更新函数，也可以最大值，最小值。
{
    tr[i]=(tr[i<<1]+tr[i<<1|1]);
    //比如t[i] = max(t[i<<1],t[i<<1|1]);
}

void bulid(ll i,ll l,ll r)//下面主函数i=1为固定的写法
{
    //i为当前需要建立的结点，l为当前需要建立区间的左端点，r则为右端点
    add_tag[i]=0;//tag数组初始化
    if(l==r){//如果左右端点相等，即为叶子结点，直接赋值即可
        tr[i]=a[l];//注意这里是l
        return;
    }
    ll mid=(l+r)>>1;
    bulid(i<<1,l,mid);//递归构造左子树
    bulid(i<<1|1,mid+1,r);//递归构造右子树
    pushup(i);//更新父节点，因为先是从上至下建树，再从下至上回溯，pushup相当于往上更新父节点的值。
}

inline void ADD(ll i,ll l,ll r,ll k)//[l,r]区间所有值加k
{
    add_tag[i]=(add_tag[i]+k);//这么写方便取余
    tr[i]=(tr[i]+(r-l+1)*k);//tr[i]是[l,r]值的和，所以加上(r-l+1)个k
}

inline void pushdown(ll i,ll l,ll r,ll mid)//下传懒标记到左右子树
{
    if((!add_tag[i])) return ;
    ADD(i<<1,l,mid,add_tag[i]);
    ADD(i<<1|1,mid+1,r,add_tag[i]);
    add_tag[i]=0; //清除标记
}

inline void update_ADD (ll i,ll l,ll r,ll x,ll y,ll k)//更新[x,y]区间，都加上k。
{
    //[l,r]为总区间，[x,y]为更新区间，通过不断二分递归[l,r]，让l,r在[x,y]中，这样的区间就符合条件组成[x,y]
    //[x,y]是定死的，是改变l,r的值
    if(l>y||r<x) return;
    if(l>=x&&r<=y) return ADD(i,l,r,k);//相当于去执行这项命令
    ll mid=(l+r)>>1;
    pushdown(i,l,r,mid);
    update_ADD(i<<1,l,mid,x,y,k);
    update_ADD(i<<1|1,mid+1,r,x,y,k);
    pushup(i);
}

ll query(ll i,ll l,ll r,ll x,ll y)
{
    ll res=0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y&&l==r){
        if(tr[i]<=k) return tr[i];
        else return 0;
    }
    ll mid=(l+r)>>1;
    if(x<=mid) res=res+query(i<<1,l,mid,x,y);
    if(y>mid)  res=res+query(i<<1|1,mid+1,r,x,y);
    return res;
}


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
int cnt;
int main()
{
    while(~scanf("%lld",&n)){
        memset(tr,0,sizeof(tr));
        memset(a,0,sizeof(a));
        printf("Case #%d:\n",++cnt);
        rep(i,1,n) a[i]=read();//cin>>a[i];
        bulid(1,1,n);
        m=read();
        //cin>>m;
        rep(i,1,m){
            //cin>>x>>y>>k;
            x=read();y=read();k=read();
            //scanf("%lld%lld%lld",&x,&y,&k);
            printf("%lld\n",query(1,1,n,x,y));
        }
}
    return 0;
}
