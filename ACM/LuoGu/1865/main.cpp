#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+1,maxn=1e5+1;
int prime[N];
int b[N];
int cnt=1;
int init(){
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=N;i++){
        if(b[i])
            prime[cnt++]=i;
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
    int n,m,l,r;
    cin>>n>>m;
    while(n--){
        cin>>l>>r;
    if(l>=1&&r>=1&&l<=m&&r<=m)
    {
        int ans1=lower_bound(prime,prime+maxn,l)-prime;
        int ans2=lower_bound(prime,prime+maxn,r)-prime;
        if(b[r])
           {ans2++;cout<<ans2-ans1<<endl;}
        else
           cout<<ans2-ans1<<endl;
    }
    else
        cout<<"Crossing the line"<<endl;
    }

    return 0;
}
