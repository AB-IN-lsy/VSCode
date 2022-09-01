/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-01 09:05:51
 * @FilePath: \GPLT\A1008\A1008.cpp
 * @LastEditTime: 2022-09-01 09:06:46
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

signed main()
{
    IOS;
    int n, res = 0;
    cin >> n;
    vector<int> a(N);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        if (a[i + 1] > a[i])
            res += 6 * (a[i + 1] - a[i]);
        else
            res += 4 * (a[i] - a[i + 1]);
    res += (n * 5);

    cout << res;
    return 0;
}