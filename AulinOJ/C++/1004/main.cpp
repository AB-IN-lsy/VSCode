#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int q[10005];
int w[10005];
int vis[10005];
int main()
{
    int m,n,i,j;
    char a,b,c;
    while(~scanf("%d",&m))
    {
        memset(w,0,sizeof(w));
        memset(vis,0,sizeof(vis));
        cin>>a>>b>>c;
        if(a=='A')
        {
            scanf("%d",&q[1]);
            for(i=2;i<=m;i++)
                scanf(",%d",&q[i]);
            cin>>b;
            for(i=1;i<=m;i++)
                for(j=1;j<i;j++)
            {
                if(q[i]>q[j])
                    w[i]++;
            }
            printf("B=(");
            cout<<w[1];
            for(i=2;i<=m;i++)
                printf(",%d",w[i]);
            printf(")\n");
        }
        else if(a=='B')
        {
            scanf("%d",&w[1]);
           for(i=2;i<=m;i++)
                scanf(",%d",&w[i]);
            cin>>b;
            int s;
             /*ѭ����������B=(0,0,0,3,1,2)�����ǹ涨A�е�6������Χ��[1,6]֮�䡣
             �Ӻ���ǰ�����������ǲ��ҵ���2��Ҳ����˵��ʱ����������ڵ���������
             �е�3����Ϊ������Ѿ��ù��������ǰ������һ�£�֤�������ٴ�ʹ��
             vis[j]=1����ʱ�����������Կ���ֻʣ��5�����������������ҵ���1��˵
             ��������ڸ��¹�������������е�2���ٴα�ǡ�֮������ظ�����Ĳ�
             ��ֱ���ҵ���������*/
           for(i=m;i>=1;i--)
               {
                   s=0;//s��ʾ��ǰ�ǵڼ������
                   for(j=0;j<m;j++)
                   {
                       if(s==w[i]&&!vis[j])// !vis[j]Ϊ��֤���е������в������Ѿ�ʹ�ù�����
                       {
                           q[i]=j;
                           vis[j]=1;
                           break;
                       }
                        if(!vis[j])//��vis[j]=1����������Ѿ�ʹ�ù��ˣ���ôs��������
                            s++;
                   }
               }
             printf("A=(");
            cout<<q[1];
            for(i=2;i<=m;i++)
                printf(",%d",q[i]);
            printf(")\n");
        }
    }
    return 0;
}
