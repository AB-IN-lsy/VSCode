#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,int>vis;
int a[101000],b[101000];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);//���뱣����Ŀ����ʱ��˳����ɴ���һ������
    }//���д��scanf("%d",&x);vis[x]++;��map����Զ���С��������Ͱ�����ⲻ����
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        vis[b[i]]=1;
    }
    for(int i=1;i<=n;i++)
     if(vis[a[i]])
      cout<<a[i]<<" ";
    return 0;
}
