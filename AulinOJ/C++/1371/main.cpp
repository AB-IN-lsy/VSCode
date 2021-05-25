#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
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
int l,r;
int main()
{
    cin>>l>>r;
    init(r);
    for(int i=l;i<=r;i++){
        if(b[i]){
            int tmp=i;
            int y=0;
            while(tmp>0){
                y=y*10+tmp%10;
                tmp=tmp/10;
            }
            if(y==i)
                cout<<i<<endl;
        }
    }
    return 0;
}
