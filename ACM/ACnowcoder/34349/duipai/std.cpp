#include <bits/stdc++.h>
#define int long long
#define ALL(X) (X).begin(), (X).end()
using namespace std;

const int MOD = 1000000007;
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    vector<int> y(m + 1);
    for (int i = 1; i <= m; ++i)
        cin >> y[i];

    sort(ALL(x));
    sort(ALL(y));

    int ansx = 0, ansy = 0;
    for (int i = 1; i <= n; ++i)
    {
        ansx = (ansx + (i - 1) * x[i] - (n - i) * x[i]) % MOD;
    }
    for (int i = 1; i <= m; ++i)
    {
        ansy = (ansy + (i - 1) * y[i] - (m - i) * y[i]) % MOD;
    }
    cout << ansx * ansy % MOD;

    return 0;
}