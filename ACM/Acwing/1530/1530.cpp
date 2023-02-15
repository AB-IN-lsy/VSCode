
#include <bits/stdc++.h>

#define int long long
#define SZ(X) ((int)X.size())

using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    int sum = accumulate(v.begin(), v.end(), 0);
    for (int i = 1; i <= n; ++i)
    {
        v[i] += v[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        r--, l--;
        cout << min(v[r] - v[l], sum - v[r] + v[l]) << '\n';
    }
    return 0;
}