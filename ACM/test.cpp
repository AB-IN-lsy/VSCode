#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m, k, l, r, ansl, ansr, sum, s;
int a[200005];
void init()
{
    ansl = ansr = -1, sum = 0, l = r = 1;
}
void update()
{
    if (r - l > ansr - ansl)
        ansr = r, ansl = l;
}
void solve()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    while (l <= n && r <= n + 1)
    {
        if (sum + s >= 0)
            update(), sum += a[r++];
        else
            sum -= a[l++];
    }
    if (ansr == -1)
        cout << -1 << endl;
    else
        cout << ansl << " " << ansr - 1 << endl;
}
signed main()
{
    cin >> t;
    while (t--)
        solve();
}
