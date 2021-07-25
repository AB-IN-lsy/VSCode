#include <bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for (ll i=(x);i<=(y);i++)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ls i<<1
#define rs i<<1|1

using namespace std;
const int N=1e6+10;
struct sa
{
    ll x;
    ll y;
    ll w;
}b[N<<2];
ll a[N<<2],tr[N<<2];
ll n,m,x,y,k;

inline void pushup(ll i)
{
    tr[i] = max(tr[ls],tr[rs]);
}
inline void bulid(ll i,ll l,ll r)
{
    if(l==r){
        tr[i]=0;
        return;
    }
    ll mid=(l+r)>>1;
    bulid(ls,l,mid);
    bulid(rs,mid+1,r);
    pushup(i);
}

inline void update(ll i,ll l,ll r,ll x,ll k)
{
    if(l>x||r<x) return;
    if(l==x&&l==r){
        tr[i]=k;
        return;
    }
    ll mid=(l+r)>>1;
    update(ls,l,mid,x,k);
    update(rs,mid+1,r,x,k);
    pushup(i);
}

ll query(ll i,ll l,ll r,ll x,ll y)
{
    ll res=-1;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return tr[i];
    ll mid=(l+r)>>1;
    if(x<=mid) res=max(res,query(ls,l,mid,x,y));
    if(y>mid)  res=max(res,query(rs,mid+1,r,x,y));
    return res;
}

bool cmp(const sa &a, const sa &b) {
    if (a.x != b.x) return a.x<b.x;
    else return a.y<b.y;
}
int t;
int main()
{
    IOS;
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n){
            cin>>b[i].x>>b[i].y>>b[i].w;
            a[i]=b[i].y;
        }
        sort(a+1,a+1+n);
        ll m=unique(a+1,a+1+n)-a-1;
        rep(i,1,n){
            b[i].y=lower_bound(a+1,a+1+m,b[i].y)-a;
        }
        sort(b+1,b+1+n,cmp);
        ///b[i].y才是真正的下标
        bulid(1,1,n);
        rep(i,1,n){
            ll q=query(1,1,n,0,b[i].y);
            update(1,1,n, b[i].y, q+b[i].w);
        }
        cout<<query(1,1,n,1,n)<<endl;
    }
    return 0;
}
/*
2
5
1 2 3
1 3 4
2 2 1
2 3 5
1 6 1
*/
