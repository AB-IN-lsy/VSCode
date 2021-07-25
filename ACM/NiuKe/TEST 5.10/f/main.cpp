#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],b[maxn];
int n,m,l,r;
ll ans;
int main()
{
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&l,&r);
        a[l]++;a[r+1]--;
    }
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    sort(b+1,b+1+n);
    for(int i=n;i>=1;i--){
        ans+=i*b[i];
    }
    printf("%lld",ans);
    return 0;
}
