/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-08 16:24:12
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.8\b.cpp
 * @LastEditTime: 2021-09-08 16:36:57
 * @brief 【CQOI2009】中位数图
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

const int N = 1e6 + 10;
int a[N], l[N << 1], r[N << 1];
int n, k;

signed main()
{
    IOS;
    cin >> n >> k;
    int pos;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == k)
            pos = i;
    }
    int sum = 0;
    for (int i = pos - 1; i >= 1; --i)
    {
        sum += (a[i] > k) ? 1 : -1;
        l[sum + n]++;
    }
    sum = 0;
    for (int i = pos + 1; i <= n; ++i)
    {
        sum += (a[i] > k) ? 1 : -1;
        r[sum + n]++;
    }
    sum = l[n] + r[n] + 1;
    for (int i = 0; i <= 2 * n; ++i)
    {
        sum += l[i] * r[2 * n - i];
    }
    cout << sum << '\n';
    return 0;
}
