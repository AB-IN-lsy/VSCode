#include <bits/stdc++.h>
#define int long long
#define ALL(X) (X).begin(), (X).end()
using namespace std;

const int MOD = 1000000007;
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    vector<int> y(m);
    for (int i = 0; i < m; ++i)
        cin >> y[i];

    sort(ALL(x));
    sort(ALL(y));

    int ansx = 0, ansy = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ansx = (ansx + i * x[i] - sum) % MOD;
        sum = (sum + x[i]) % MOD;
    }
    sum = 0;
    for (int i = 0; i < m; ++i)
    {
        ansy = (ansy + i * y[i] - sum) % MOD;
        sum = (sum + y[i]) % MOD;
    }
    cout << ansx * ansy % MOD;

    return 0;
}