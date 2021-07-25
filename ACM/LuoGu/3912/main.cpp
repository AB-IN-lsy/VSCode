#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+10;
int cnt=0;
int prime[N];
bool b[N];
int init(int n){
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=n;i++){
        if(b[i])
            prime[++cnt]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=n;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }
    }
    return 0;
}
int n,ans;
int main()
{
    cin>>n;
    init(n);
    for(int i=1;i<=n;i++){
        if(b[i])
        ans++;
    }
    cout<<ans;
    return 0;
}
