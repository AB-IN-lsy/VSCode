#include <bits/stdc++.h>
using namespace std;
int m,n,k,flag;
int a[100001];
bool vis[100001];
void dfs(int x,int cnt)
{
    if(cnt>k||x<0||flag)
        return;
    if(x==0)
    {
        if(cnt==k)
        {
            flag=1;
            return;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            dfs(x-a[i],cnt+1);
            vis[i]=false;
        }
    }
}
int main()
{
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(m,0);
    if(flag==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
