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

int min1(int l,int r){
    int i=l;
    for(int i=l;i<=r;i++){
        if(b[i])
        {
            return i;
            break;
        }
    }
    return 0;
}

int max1(int l,int r){
    int i=r;
    for(int i=r;i>=l;i--){
        if(b[i])
        {
            return i;
            break;
        }
    }
    return 0;
}

int main()
{
    init();
    int n;
    cin>>n;
    ll ans=0;
    while(n--){
        int l,r;
        cin>>l>>r;
        ans=ans+min1(l,r)+max1(l,r);
    }
    cout<<ans;
    return 0;
}
