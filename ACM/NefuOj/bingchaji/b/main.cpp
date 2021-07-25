#include <bits/stdc++.h>
#define min3(a,b,c) min(min(a,b),min(b,c))
#define max3(a,b,c) max(max(a,b),max(b,c))
using namespace std;
int a,b,mn,mx,cnt,flag,pre[100001],vis[100001];
int find(int x)
{
    if(x!=pre[x])pre[x]=find(pre[x]);
    return pre[x];
}
void join(int a,int b)
{
    int a1=find(a),b1=find(b);
    if(a1!=b1){pre[a1]=b1;flag=0;}
    else flag=1;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b&&!(a==-1&&b==-1))
    {
        if(a==0&&b==0){printf("Yes\n");continue;}
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=100001;i++)
            pre[i]=i;
        mn=0x3f3f3f3f;mx=cnt=flag=0;
        while(!(a==0&&b==0))
        {
            vis[a]=vis[b]=1;
            mn=min3(a,b,mn);mx=max3(a,b,mx);
            if(flag==0)join(a,b);
            cin>>a>>b;
        }
        if(flag==1){printf("No\n");continue;}
        for(int i=mn;i<=mx;i++)
        if(vis[i]&&pre[i]==i)cnt++;
        cnt==1?printf("Yes\n"):printf("No\n");
    }
    return 0;
}
