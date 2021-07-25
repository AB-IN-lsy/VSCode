#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int cnt=0,n;
int prime[5000010];
bool b[N];
int init(){//筛出素数数组
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
bool judge(int x)//将数倒过来的函数，如输入了107，则a[0]=0,a[1]=7.a[2]=0,a[3]=1
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
            s=s*10+a[j];//第一次是7,第二次是07，第三次107
        if(!b[s])return 0;//看这个数在不在素数集（采用的桶排序，若b[100]=0,则100不为素数。)中，
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
