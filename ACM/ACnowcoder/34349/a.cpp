#include <bits/stdc++.h>

using namespace std;
#define ULL unsigned long long
#define SZ(X) ((int)X.size())
const int P = 131;
const int N = 2e5 + 10;

ULL h[N], p[N], hr[N];

int main()
{
    p[0] = 1;
    string s;
    cin >> s;
    int n = SZ(s);
    s = " " + s;

    for (int i = 1; i <= n; ++i)
    {
        hr[i] = hr[i - 1] * P + s[n - i + 1] - '0';
        h[i] = h[i - 1] * P + s[i] - '0';
        p[i] = p[i - 1] * P;
    }

    auto get = [&](ULL *h, int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; };

    auto check = [&](int l, int r) { return get(h, l, r) == get(hr, n - r + 1, n - l + 1); };

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (check(1, i) && check(1, (i + 1) / 2))
            ans++;
    }
    cout << ans;

    return 0;
}