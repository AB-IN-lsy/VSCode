#include <bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll a[maxn<<2],tr[maxn<<2],add_tag[maxn<<2],    mul_tag[maxn<<2];
//  ԭ����     �߶���      �ӷ�lazy_tag���    �˷�lazy_tag���
ll n,m,p,op1,x,y,k;

inline void pushup(ll i)//���º�����Ҳ�������ֵ����Сֵ��
{
    tr[i]=(tr[i<<1]+tr[i<<1|1])%p;
    //����t[i] = max(t[i<<1],t[i<<1|1]);
}

void bulid(ll i,ll l,ll r)
{
    //iΪ��ǰ��Ҫ�����Ľ�㣬lΪ��ǰ��Ҫ�����������˵㣬r��Ϊ�Ҷ˵�
    add_tag[i]=0;mul_tag[i]=1;//tag�����ʼ��
    if(l==r){//������Ҷ˵���ȣ���ΪҶ�ӽ�㣬ֱ�Ӹ�ֵ����
        tr[i]=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    bulid(i<<1,l,mid);//�ݹ鹹��������
    bulid(i<<1|1,mid+1,r);//�ݹ鹹��������
    pushup(i);//���¸��ڵ㣬��Ϊ���Ǵ������½������ٴ������ϻ��ݣ�pushup�൱�����ϸ��¸��ڵ��ֵ��
}

inline void ADD(ll i,ll l,ll r,ll k)//[l,r]��������ֵ��k
{
    add_tag[i]=(add_tag[i]+k)%p;//��ôд����ȡ��
    tr[i]=(tr[i]+(r-l+1)*k)%p;//tr[i]��[l,r]ֵ�ĺͣ����Լ���(r-l+1)��k
}

inline void MUL(ll i,ll l,ll r,ll k)//[l,r]��������ֵ��k
{
    add_tag[i]=add_tag[i]*k%p;//�ӷ����Ҳ�óˣ���Ϊ�˷������ȼ��ȼӷ���
    tr[i]=tr[i]*k%p;
    mul_tag[i]=mul_tag[i]*k%p;
}

inline void pushdown(ll i,ll l,ll r,ll mid)//�´�����ǵ���������
{
    if(mul_tag[i]==1&&(!add_tag[i])) return ;
    MUL(i<<1,l,mid,mul_tag[i]);
    MUL(i<<1|1,mid+1,r,mul_tag[i]);
    mul_tag[i]=1;

    ADD(i<<1,l,mid,add_tag[i]);
    ADD(i<<1|1,mid+1,r,add_tag[i]);
    add_tag[i]=0;
}

inline void update_ADD (ll i,ll l,ll r,ll x,ll y,ll k)//����[x,y]���䣬������k��
{
    //[l,r]Ϊ�����䣬[x,y]Ϊ�������䣬ͨ�����϶��ֵݹ�[l,r]����l,r��[x,y]�У�����������ͷ����������[x,y]
    //[x,y]�Ƕ����ģ��Ǹı�l,r��ֵ
    if(l>y||r<x) return;
    if(l>=x&&r<=y) return ADD(i,l,r,k);
    ll mid=(l+r)>>1;
    pushdown(i,l,r,mid);
    update_ADD(i<<1,l,mid,x,y,k);
    update_ADD(i<<1|1,mid+1,r,x,y,k);
    pushup(i);
}

inline void update_MUL (ll i,ll l,ll r,ll x,ll y,ll k)//����[x,y]���䣬������k��
{
    if(l>y||r<x) return;
    if(l>=x&&r<=y) return MUL(i,l,r,k);
    ll mid=(l+r)>>1;
    pushdown(i,l,r,mid);//�´���Ǻ��������������
    update_MUL(i<<1,l,mid,x,y,k);
    update_MUL(i<<1|1,mid+1,r,x,y,k);
    pushup(i);
}

ll query(ll i,ll l,ll r,ll x,ll y)
{
    ll res=0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i];//��������ʱ�������±��Ӧ��ֵ���ɡ�
    ll mid=(l+r)>>1;
    pushdown(i,l,r,mid);
    if(x<=mid) res=(res+query(i<<1,l,mid,x,y))%p;
    if(y>mid)  res=(res+query(i<<1|1,mid+1,r,x,y))%p;
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
    n=read();m=read();p=read();
    rep(i,1,n) a[i]=read();
    bulid(1,1,n);
    rep(i,1,m){
        op1=read();
        if(op1==1){
            x=read();y=read();k=read();
            update_MUL(1,1,n,x,y,k);
        }
        if(op1==2){
            x=read();y=read();k=read();
            update_ADD(1,1,n,x,y,k);
        }
        if(op1==3){
            x=read();y=read();
            printf("%lld\n",query(1,1,n,x,y));
        }
    }
    return 0;
}
