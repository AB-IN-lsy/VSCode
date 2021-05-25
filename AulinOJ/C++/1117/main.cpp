#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int cnt=0,n;
int prime[N];
bool b[N];
int init(){
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

int main()
{
    init();
    int x;
    cin>>x;
    for(int i=1;i<=x;i++){
        if(x%prime[i]==0)
        {
            cout<<x/prime[i]<<endl;
            break;
        }
    }
    return 0;
}
