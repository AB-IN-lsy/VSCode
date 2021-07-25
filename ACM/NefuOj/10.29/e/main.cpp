#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[50010],mx,mn;
int main()
{
    while(~scanf("%lld", &n))
    {

        mn = -0x3f3f3f3f;
        for(int i = 1; i <= n;i++){
            scanf("%lld", &a[i]);
            mn = max(mn , a[i]);
        }
        mx = -0x3f3f3f3f;
        ll ans = 0 , cnt = 0;
        bool f = 1;
        for(int i = 1; i <= n;i++){
            if(a[i] > 0) {
                ans += a[i];
                mx = max(mx , ans);
            }
            else{
                if(f && ans > 0) cnt = mx , f = 0;
                ans = 0;
            }
        }
        if(a[1] > 0 && a[n] > 0)  mx = max(mx , cnt + ans);
        if(mx == -0x3f3f3f3f) mx = mn;
        printf("%lld\n",mx);
    }

    return 0;
}
