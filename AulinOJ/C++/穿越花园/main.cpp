#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+1,mod=1000000007;
int fac[N];
void exgcd(int a,int b,int &x,int &y){
    if(b==0){x=1,y=0;}
    else{exgcd(b,a%b,y,x);y-=a/b*x;}
}
int inv(int a,int p){
    int x,y;
    exgcd(a,p,x,y);
    if(x<0) x=(x%p+p)%p;
    return x;
}
void cal(){
    fac[0]=1;
    for(int i=1;i<N;++i)
        fac[i]=1LL*fac[i-1]*i%mod;
}
int c(int n,int m){
    return (1LL*fac[n]*inv(fac[m],mod)%mod*inv(fac[n-m],mod)%mod);
}
int main(){
    freopen("write.txt","w",stdout);
    cal();
    int T,n,m;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d %d",&n,&m);
        printf("%d\n",c(n+m-2,m-1));
    }
    return 0;
}
