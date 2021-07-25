#include <bits/stdc++.h>
using namespace std;
int ans,cnt,mx;
struct sa
{
    int price;
    int imp;
}m[1000];

int cmp(const struct sa &a,const struct sa &b)
{
    if(a.imp!=b.imp) return a.imp>b.imp;
    else return a.price<b.price;
}

int main()
{
    int maxn,n;
    cin>>maxn>>n;
    ios::sync_with_stdio(false);
    for(int i=0;i<n;i++){
        cin>>m[i].price>>m[i].imp;
    }
    for(int i=0;i<(1<<n);i++){
        ans=0;cnt=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
            {ans+=m[j].price*m[j].imp;cnt+=m[j].price;}
        }
        if(cnt<maxn)
            mx=max(mx,ans);
    }
    cout<<mx<<endl;
    return 0;
}
