/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-23 09:44:55
 * @FilePath: \ACM\Acwing\4262\4262.cpp
 * @LastEditTime: 2022-06-23 09:48:39
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        b[i] = a[i] - b[i];
    }

    vector<int> c(n + 1);
    int neg = 0, pos = 0;
    for (int i = 1; i <= n; ++i)
    {
        c[i] = b[i] - b[i - 1];
        if (c[i] < 0)
            neg -= c[i];
        else
            pos += c[i];
    }

    cout << max(pos, neg) << '\n';
    return 0;
}