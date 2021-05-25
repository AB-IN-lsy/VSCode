#pragma GCC optimize(2)
#include <iostream>
typedef long long ll;
using namespace std;
ll a[2000002],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1]+i;
    for(int i=1;i<=n;i++){
        ll mid=a[i-1]+n;
        ll ans=lower_bound(a+1,a+n+1,mid)-a;
        if(a[ans]-a[i-1]==n){
            if(ans!=i) printf("%d %d\n",i,ans);
        }
    }
    return 0;
}
