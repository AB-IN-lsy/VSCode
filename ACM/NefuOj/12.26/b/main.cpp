#include <bits/stdc++.h>
using namespace std;
map<int,map<int,int> >vis;
int main()
{
    ios::sync_with_stdio(0);
    int n,l,r,maxn;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        if(vis.find(r)!=vis.end())
        {
            vis[r]={max(vis[r].first,l),vis[r].second+1};
        }
        else vis[r]={l,1};
    }
    map<int,map<int,int> >::iterator it;
    maxn=0;
    for(it=vis.begin();it!=vis.end();it++)
    {
        if(it->second->first>maxn)
        {
            maxn=it->second->first;
            sum+=(long long)maxn*(it->second->second);
        }
        else
        {
            sum+=(long long)maxn*(it->second->second);
        }
    }
    printf("%lld\n",sum);
    return 0;
}
