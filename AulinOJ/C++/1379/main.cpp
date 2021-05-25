#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int cnt=0;
int prime[N];
bool b[N];
void init(){
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
}
int n,ans;
int main()
{
    init();
    for(int i=100;i<=200;i++){
        if(b[i])
          ans++;
    }
    cout<<ans<<endl;
    for(int i=100;i<=200;i++){
        if(b[i])
          cout<<i<<" ";
    }
    return 0;
}
