#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10;
int n,a[N],b[N];
struct node
{
    int x,y;
    ll sum;
};
bool operator < (const node &s1,const node &s2)
{return s1.sum>s2.sum;}
priority_queue<node,vector<node> >q;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        q.push({i,1,a[i]+b[1]});
    for(int i=1;i<=n;i++)
    {
        node tmp=q.top();
        q.pop();
        i==n?printf("%lld",tmp.sum):printf("%lld\n",tmp.sum);
        int x=tmp.x,y=tmp.y;
        q.push({x,y+1,a[x]+b[y+1]});
    }
    return 0;
}
