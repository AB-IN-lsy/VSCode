#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll a[maxn<<2],tr[maxn<<2],mx[maxn<<2];
//  ԭ����     �߶���      �ӷ�lazy_tag���
ll n,m,p,op1,x,y,k;

inline void pushup(ll i)//���º�����Ҳ�������ֵ����Сֵ��
{
    tr[i]=(tr[i<<1]+tr[i<<1|1]);
    mx[i]=max(mx[i<<1],mx[i<<1|1]);
    //����t[i] = max(t[i<<1],t[i<<1|1]);
}

void bulid(ll i,ll l,ll r)//����������i=1Ϊ�̶���д��
{
    //iΪ��ǰ��Ҫ�����Ľ�㣬lΪ��ǰ��Ҫ�����������˵㣬r��Ϊ�Ҷ˵�
    if(l==r){//������Ҷ˵���ȣ���ΪҶ�ӽ�㣬ֱ�Ӹ�ֵ����
        tr[i]=a[l];//ע��������l
        mx[i]=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    bulid(i<<1,l,mid);//�ݹ鹹��������
    bulid(i<<1|1,mid+1,r);//�ݹ鹹��������
    pushup(i);//���¸��ڵ㣬��Ϊ���Ǵ������½������ٴ������ϻ��ݣ�pushup�൱�����ϸ��¸��ڵ��ֵ��
}

inline void SQRT(ll i,ll l,ll r)
{
    tr[i]=sqrt(tr[i]);
    mx[i]=tr[i];
}

inline void update_SQRT (ll i,ll l,ll r,ll x,ll y)//����[x,y]���䣬������k��
{
    //[l,r]Ϊ�����䣬[x,y]Ϊ�������䣬ͨ�����϶��ֵݹ�[l,r]����l,r��[x,y]�У�����������ͷ����������[x,y]
    //[x,y]�Ƕ����ģ��Ǹı�l,r��ֵ
    if(mx[i]<=1) return;
    if(l>y||r<x) return;
    if(l==r) return SQRT(i,l,r);
    ll mid=(l+r)>>1;
    update_SQRT(i<<1,l,mid,x,y);
    update_SQRT(i<<1|1,mid+1,r,x,y);
    pushup(i);
}

ll query(ll i,ll l,ll r,ll x,ll y)
{
    ll res=0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i];//��������ʱ�������±��Ӧ��ֵ���ɡ�
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

int main()
{
    //cin>>n;
    n=read();
    rep(i,1,n) a[i]=read();
    bulid(1,1,n);
    //cin>>m;
    m=read();
    rep(i,1,m){
        //cin>>op1;
        op1=read();
        if(op1==2){
            //cin>>x>>y;
            x=read();y=read();
            update_SQRT(1,1,n,x,y);
        }
        if(op1==1){
            //cin>>x>>y;
            x=read();y=read();
            printf("%lld\n",query(1,1,n,x,y));
        }
    }
    return 0;
}
