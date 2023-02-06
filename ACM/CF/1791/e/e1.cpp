/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-04 14:02:33
 * @FilePath: \CF\1791\e\e1.cpp
 * @LastEditTime: 2023-02-04 14:28:27
 */
/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-03 22:35:26
 * @FilePath: \CF\1791\e\e.cpp
 * @LastEditTime: 2023-02-04 11:07:18
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

void solve()
{
    int n, sum = 0, neg = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            neg++;
            a[i] = -a[i];
        }
        sum += a[i];
    }
    if (neg % 2)
    {
        int mn = *min_element(ALL(a));
        sum -= 2 * mn;
    }
    cout << sum << '\n';

    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}