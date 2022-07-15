/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-30 00:11:46
 * @FilePath: \ACM\LeetCode\15\15.cpp
 * @LastEditTime: 2022-07-09 19:59:10
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << endl
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] %= 10;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        int k = n - 1;
        int t = (3 - a[i] + 10) % 10;

        for (int j = i + 1; j < n; ++j)
        {
            if (j > i + 1 && a[j] == a[j - 1])
                continue;
            while (j < k && (a[j] + a[k]) % 10 < t)
                k--;

            if (j == k)
                break;
            if ((a[j] + a[k]) % 10 == t)
            {
                puts("YES");
                return;
            }
        }
    }
    puts("NO");
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}