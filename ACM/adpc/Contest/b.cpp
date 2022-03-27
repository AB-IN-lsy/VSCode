/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-27 10:46:13
 * @FilePath: \ACM\Contest\b.cpp
 * @LastEditTime: 2022-03-27 17:21:26
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

int n, a[N], b[N];
bool check(int x)
{
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int r = a[i] + x;
        int l = a[i] - x;
        b[i] = max(l, b[i - 1] + 1);
        if (b[i] > r || b[i] < l)
            return false;
    }
    return true;
}

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 1e9;
    int ans = -1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << '\n';
}
