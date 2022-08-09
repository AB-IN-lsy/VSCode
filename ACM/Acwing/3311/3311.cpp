/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-04 16:15:18
 * @FilePath: \Acwing\3311\3311.cpp
 * @LastEditTime: 2022-08-04 16:30:43
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int i = 1, j = 2, ans = 2;
        while (i <= n && j <= n)
        {
            int d = a[j] - a[i];
            while (j <= n && a[j] - a[j - 1] == d)
                j++;
            ans = max(ans, j - i);
            i = j - 1;
        }
        printf("Case #%lld: %lld\n", _, ans);
    }
    return 0;
}