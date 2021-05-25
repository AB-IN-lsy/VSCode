#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * @param num: array of num
     * @param ask: Interval pairs
     * @return: return the sum of xor
     */

     #define ll long long
     struct sa{
        ll mn;
        ll mx;
    }tr[100000<<2];
    inline void pushup(ll i)
    {
        tr[i].mn = min(tr[i<<1].mn,tr[i<<1|1].mn);
        tr[i].mx = max(tr[i<<1].mx,tr[i<<1|1].mx);
    }
    void bulid(ll i,ll l,ll r)
    {
        if(l==r){
            tr[i].mn=1e9;
            tr[i].mx=-1;
            return;
        }
        ll mid=(l+r)>>1;
        bulid(i<<1,l,mid);
        bulid(i<<1|1,mid+1,r);
        pushup(i);
    }
    inline void update (ll i,ll l,ll r,ll x,ll y)
    {
        if(l>x||r<x) return;
        if(l==x&&l==r){
            tr[i].mn=y;
            tr[i].mx=y;
            return;
        }
        ll mid=(l+r)>>1;
        update(i<<1,l,mid,x,y);
        update(i<<1|1,mid+1,r,x,y);
        pushup(i);
    }
    ll query_min(ll i,ll l,ll r,ll x,ll y)
    {
        ll res=1e9;
        if(l>y||r<x) return 0;
        if(l>=x&&r<=y) return tr[i].mn;
        ll mid=(l+r)>>1;
        if(x<=mid) res=min(res,query_min(i<<1,l,mid,x,y));
        if(y>mid)  res=min(res,query_min(i<<1|1,mid+1,r,x,y));
        return res;
    }
    ll query_max(ll i,ll l,ll r,ll x,ll y)
    {
        ll res=-1;
        if(l>y||r<x) return 0;
        if(l>=x&&r<=y) return tr[i].mx;
        ll mid=(l+r)>>1;
        if(x<=mid) res=max(res,query_max(i<<1,l,mid,x,y));
        if(y>mid)  res=max(res,query_max(i<<1|1,mid+1,r,x,y));
        return res;
    }
    int Intervalxor(vector<int> &num, vector<vector<int>> &ask) {
        int n=num.size(),cnt=0;
        bulid(1,1,n);
        for(int i=1;i<=n;i++) update(1,1,n,i,num[i-1]);
        for(auto i:ask){
            ll ans=0;
            ans+=query_max(1,1,n,i[0],i[1]);
            ans-=query_min(1,1,n,i[2],i[3]);
            cnt^=ans;
        }
        return cnt;
        // write your code here
    }
};
int main()
{
    Solution solution;
    cout<<solution.Intervalxor( [1,2,3,4,5] , [[1,2,3,4],[1,2,4,5]] )<<endl;
    return 0;
}
