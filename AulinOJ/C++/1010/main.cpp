#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x,x1,j1,j2,sum=0,tmp;
    scanf("%lld<%lld>%lld",&x,&j1,&j2);
    x1=x;

    int n=log10(x)+1;
    for(int i=0;i<n;i++){
        tmp=x%10;
        sum+=tmp*pow(j1,i);
        x=x/10;
    }

    int a[100]={0},k=0;
    while(sum){
        a[k++]=sum%j2;
        sum/=j2;
    }
    printf("%lld<%lld>=",x1,j1);
    for(int i=k-1;i>=0;i--){
        printf("%d",a[i]);
    }
    printf("<%lld>",j2);
    return 0;
}
