#include <bits/stdc++.h>

using namespace std;

int n, m;
long long x[100050];
long long y[100050];
const long long mod = 1e9 + 7;
long long ans, ans1, ans2;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &x[i]);
    for (int j = 1; j <= m; ++j)
        scanf("%lld", &y[j]);
    sort(x + 1, x + n + 1);
    sort(y + 1, y + m + 1);
    for (int i = 1; i <= n; ++i)
        ans1 = (ans1 + (i - 1) * x[i] - (n - i) * x[i]) % mod;
    for (int i = 1; i <= m; ++i)
        ans2 = (ans2 + (i - 1) * y[i] - (m - i) * y[i]) % mod;
    // cout << ans1 << ' ' << ans2 << endl;
    ans = (ans1 * ans2) % mod;
    cout << ans << endl;
    return 0;
}
