#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=5e6+10;
ll n,k,a[maxn],ans;
int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ans=unique(a+1,a+n+1)-a;//给数组a去重，并保留ans=去重后非伪的长度
    if(k<ans)
        printf("%lld",a[k]);
    else
        printf("NO RESULT");
    return 0;
}
