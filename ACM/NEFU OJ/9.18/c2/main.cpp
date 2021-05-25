#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rint register int
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,ans,a[N],b[N],sum;
int main()
{
    IOS;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ans=0;
        sum=0;
        for(rint i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%3!=0){
            printf("0\n");
            continue;
        }
        ll tot=0;
        for(rint i=1;i<=n;i++){
            tot+=a[i];
            if(tot==sum*2/3&&i!=1&&i!=n){
                b[i]++;
            }
            b[i]+=b[i-1];
        }
        tot=0;
        for(rint i=1;i<=n;i++){
            tot+=a[i];
            if(tot==sum/3&&i!=n)
                ans+=b[n]-b[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
