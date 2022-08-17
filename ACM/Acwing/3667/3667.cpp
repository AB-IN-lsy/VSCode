/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 10:42:37
 * @FilePath: \Acwing\3667\3667.cpp
 * @LastEditTime: 2022-08-17 10:48:11
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
    int x;
    while (cin >> x)
    {
        if (x & 1)
        {
            cout << "0\n";
        }
        else
        {
            int ans = x / 4;
            if (x % 4 == 0)
                ans--;
            cout << ans << '\n';
        }
    }
    return 0;
}