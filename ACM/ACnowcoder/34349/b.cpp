#include <bits/stdc++.h>

using namespace std;
#define int long long
#define SZ(X) ((int)X.size())
typedef pair<int, int> PII;

signed main()
{
    int n;
    scanf("%lld", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    int ans = 0;
    stack<PII> s; // first 值 second 下标
    for (int i = 1; i <= n; ++i)
    {
        while (SZ(s) && s.top().first > a[i])
            s.pop();
        if (SZ(s) && s.top().first == a[i])
            ans = max(ans, i - s.top().second);
        s.push({a[i], i});
    }
    cout << ans;
    return 0;
}