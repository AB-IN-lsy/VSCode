//��ȡ�����������ڣ�
#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,k,l,r,a[N];
bool judge()//�õĺ�����һ���ı�����д�ں������棩�������������ﶨ�塣
{
    int tmps=0;
    for(l=1,r=1;r<=n;r++)//ͬ���ȡ�жϺ���
    {
        tmps+=a[r];
        while(tmps>k&&l<r)//�ӵڶ�������ʼ����1��2������������k����ѵ�һ���µ���β�ͺ�ͷ���ڵڶ�����
        tmps-=a[l],
        l++;
        if(tmps==k)
        return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(judge())
        printf("%d %d\n",l,r);
    else
        printf("tiangeniupi\n");
    return 0;
}
