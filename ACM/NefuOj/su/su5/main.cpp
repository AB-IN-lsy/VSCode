#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int cnt=0,n;
int prime[5000010];
bool b[N];
int init(){//ɸ����������
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=N;i++){
        if(b[i])
            prime[++cnt]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=N;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }
    }
    return 0;
}
bool judge(int x)//�����������ĺ�������������107����a[0]=0,a[1]=7.a[2]=0,a[3]=1
{
    int a[8],len=0;
    memset(a,0,sizeof(a));
    while(x)
    {
        a[++len]=x%10;
        x=x/10;
    }
    for(int i=1;i<=len;i++)
    {
        int s=0;
        for(int j=i;j>=1;j--)
            s=s*10+a[j];//��һ����7,�ڶ�����07��������107
        if(!b[s])return 0;//��������ڲ��������������õ�Ͱ������b[100]=0,��100��Ϊ������)�У�
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    init();
    while(cin>>n)
    {
        if(judge(n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
