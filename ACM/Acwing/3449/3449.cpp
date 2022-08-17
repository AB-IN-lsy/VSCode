/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 15:42:33
 * @FilePath: \Acwing\3449\3449.cpp
 * @LastEditTime: 2022-08-17 15:47:47
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
    string n;
    while (cin >> n, n != "0")
    {
        while (SZ(n) > 1)
        {
            int ans = 0;
            for (auto i : n)
            {
                ans += i - '0';
            }
            n = to_string(ans);
        }
        cout << n << '\n';
    }
    return 0;
}