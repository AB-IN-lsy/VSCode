/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-08 00:25:01
 * @FilePath: \Acwing\3438\3438.cpp
 * @LastEditTime: 2022-08-08 01:03:17
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
    int a, b;
    string n;
    cin >> a >> n >> b;

    reverse(n.begin(), n.end());
    int base = 1, res = 0;

    // 转成十进制
    for (auto i : n)
    {
        int k;
        if (i >= '0' && i <= '9')
        {
            k = i - '0';
        }
        else
        {
            int a = i & 63;
            if (a <= 26)
                k = a + 9;
            else
                k = a - 23;
        }
        res += k * base;
        base *= a;
    }

    // 转成b进制
    string ans;
    while (res)
    {
        int a = res % b;
        if (a >= 10)
            ans += ('A' + a - 10);
        else
            ans += (a + '0');
        res /= b;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}