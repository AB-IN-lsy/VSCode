/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-07 20:27:13
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\I.cpp
 * @LastEditTime: 2021-09-08 16:23:46
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
LL a[N], sum[N];
LL n, k, m;
bool check(int x)
{
    for (int i = 1; i + x - 1 <= n; ++i)
    {
        int j = i + x - 1;
        m = i + j >> 1; //midian
        LL left = sum[m - 1] - sum[i - 1];
        LL right = sum[j] - sum[m];
        if (abs(left - (m - i) * a[m]) + abs(right - (j - m) * a[m]) <= k)
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    IOS;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}