#include <bits/stdc++.h>
using namespace std;
map<int,int>vis;
int main()
{
    int n,x,num,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        vis[x]+=i;//��Ҫ�����ֵ��������
    }
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        scanf("%d",&y);
        printf("%d",vis[y]);//����дif(x==y) Ȼ���ڿ�һ��ѭ�����ң�ֱ�ӽ�y��ֵ����map��
    }
    return 0;
}
