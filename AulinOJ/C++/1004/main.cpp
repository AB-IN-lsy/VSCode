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
             /*循环解析：例B=(0,0,0,3,1,2)，我们规定A中的6个数范围在[1,6]之间。
             从后往前来，首先我们查找到了2，也就是说此时这个数在现在的数组中排
             行第3大，因为这个数已经用过所以我们把它标记一下，证明不能再次使用
             vis[j]=1。此时这个数组里可以看作只剩下5个数，我们现在又找到了1，说
             明这个数在更新过后的数组里排行第2大，再次标记。之后就是重复上面的操
             作直到找到所有数。*/
           for(i=m;i>=1;i--)
               {
                   s=0;//s表示当前是第几大的数
                   for(j=0;j<m;j++)
                   {
                       if(s==w[i]&&!vis[j])// !vis[j]为保证现有的排序中不存在已经使用过的数
                       {
                           q[i]=j;
                           vis[j]=1;
                           break;
                       }
                        if(!vis[j])//若vis[j]=1，即这个数已经使用过了，那么s不自增。
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
