#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt1, cnt2, x, y;

bool check(ll mid)
{
    ll sheng_yu = mid - (mid / y) - (mid / x) + (mid / (x * y));
    ll cnt1_ans = max((ll) 0, cnt1 - (mid / y) + (mid / (x * y)));
    ll cnt2_ans = max((ll) 0, cnt2 - (mid / x) + (mid / (x * y)));
    return cnt1_ans + cnt2_ans <= sheng_yu;
}

ll bsearch_1(ll l, ll r)
{
    while (l < r){
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve()
{
    scanf("%lld%lld%lld%lld", &cnt1, &cnt2, &x, &y);
    printf("%d\n", bsearch_1(1, (cnt1 + cnt2) * 2 + 1));
}

int main()
{
    solve();
    return 0;
}
