#include <bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
typedef long long ll;
using namespace std;
const int maxn=1e5+10;
struct sa{
    ll sum;
    ll gcd;
    ll gap;
}tr[maxn<<2];
ll a[maxn<<2],b[maxn<<2],l,r,n,m,op1,y;
inline void pushup(ll i)
{
    tr[i].sum = (tr[ls].sum+tr[rs].sum);
    tr[i].gcd = __gcd(tr[ls].gcd,tr[rs].gcd);
    tr[i].gap = max(tr[ls].gap,tr[rs].gap);
}

void bulid(ll i,ll l,ll r)
{
    if(l==r){
        tr[i].sum=a[l];
        tr[i].gcd=abs(a[l]);
        tr[i].gap=abs(a[l]);
        return;
    }
    ll mid=(l+r)>>1;
    bulid(ls,l,mid);
    bulid(rs,mid+1,r);
    pushup(i);
}

inline void update (ll i,ll l,ll r,ll x,ll y)
{
    if(l>x||r<x) return;
    if(l==x&&l==r) {
        tr[i].sum+=y;
        tr[i].gcd=abs(tr[i].sum);
        tr[i].gap=abs(tr[i].sum);
        return;
    }
    ll mid=(l+r)>>1;
    update(ls,l,mid,x,y);
    update(rs,mid+1,r,x,y);
    pushup(i);
}

ll query_sum(ll i,ll l,ll r,ll x,ll y)
{
    ll res=0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i].sum;
    ll mid=(l+r)>>1;
    if(x<=mid) res=res+query_sum(ls,l,mid,x,y);
    if(y>mid)  res=res+query_sum(rs,mid+1,r,x,y);
    return res;
}

ll query_gcd(ll i,ll l,ll r,ll x,ll y)
{
    ll res=0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i].gcd;
    ll mid=(l+r)>>1;
    if(x<=mid) res= __gcd(res,query_gcd(ls,l,mid,x,y));
    if(y>mid)  res= __gcd(res,query_gcd(rs,mid+1,r,x,y));
    return res;
}

ll query_gap(ll i,ll l,ll r,ll x,ll y)
{
    ll res=0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i].gap;
    ll mid=(l+r)>>1;
    if(x<=mid) res= max(res,query_gap(ls,l,mid,x,y));
    if(y>mid)  res= max(res,query_gap(rs,mid+1,r,x,y));
    return res;
}

int main()
{
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    cin>>n>>m;
    rep(i,1,n) cin>>b[i],a[i]=b[i]-b[i-1];
    bulid(1,1,n);
    rep(i,1,m){
        cin>>op1>>l>>r;
        if(op1==1){
            cin>>y;
            update(1,1,n,l,y);
            if(r<n) update(1,1,n,r+1,-y);
        }
        else if(op1==2){
            cout<<query_gap(1,1,n,l+1,r)<<endl;
        }
        else{
            cout<<abs(__gcd(query_sum(1,1,n,1,l),query_gcd(1,1,n,l+1,r)))<<endl;
        }
    }
    return 0;
}
