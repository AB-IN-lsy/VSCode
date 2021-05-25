#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,int>vis;
int a[101000],b[101000];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);//若想保持题目输入时的顺序，则可创建一个数组
    }//如果写成scanf("%d",&x);vis[x]++;则map里会自动从小到大排序，桶排在这不可用
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        vis[b[i]]=1;
    }
    for(int i=1;i<=n;i++)
     if(vis[a[i]])
      cout<<a[i]<<" ";
    return 0;
}
