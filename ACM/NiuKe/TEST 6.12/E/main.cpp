#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int ans;
void f(long long n)
{
    ans=0;
    while(n%2==0){
        n/=2;
        a[++ans] = n;
    }
    long long x=1;
    for(int i=1;n;i++){
        if(n%2){
            a[++ans]=x;
        }
        x*=2;n/=2;
    }
}
int main()
{
    int t,n,cnt;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1) n=2;
        cnt=0;
        long long x=n;
        while(x%2==0) {x=x>>1;cnt++;}
        if(x==1){
            x=3;
            x*=n;
            printf("%lld %d\n",x,cnt+2);
            while(x%2==0){
                x=x>>1;
                printf("%lld ",x);
            }
            printf("2 1\n");
        }
        else{
            x=pow(2,floor(log2(x)));
            x*=n;
            f(x);
            //cout<<x<<endl;
            //long long sum =0;
            printf("%lld %d\n",x,ans);
            for(int i=1;i<=ans;i++){
                if(i!=1) printf(" ");
                printf("%lld",a[i]);
                //sum+=a[i];
            }
            printf("\n");
            //if(sum == x) printf("%lld %lld %d\n",sum,x,sum==x);
        }
    }
    return 0;
}
