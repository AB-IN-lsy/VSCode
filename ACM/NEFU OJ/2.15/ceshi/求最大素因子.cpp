#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1;
int prime[N];
int b[N];
int cnt=0;
 int init(){
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=1000000;i++){
        if(b[i])
            prime[++cnt]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=1000000;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    int x,flag;
    init();
    while(cin>>x)
    {
      flag=0;
      for(int i=cnt;i>=1;i--)//求最大的素因子，cnt是记弄了多少个素数，那就cnt--,从大到小筛选。
      if (x%prime[i]==0)
        {
         flag=i;
         break;
        }
      cout<<flag<<endl;
    }

    return 0;
}
