#include <bits/stdc++.h>
using namespace std;
map<int,int>vis;
int main()
{
    int n,x,num,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        vis[x]+=i;//将要输出的值留在外面
    }
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        scanf("%d",&y);
        printf("%d",vis[y]);//不用写if(x==y) 然后在开一个循环查找，直接将y的值带入map中
    }
    return 0;
}
