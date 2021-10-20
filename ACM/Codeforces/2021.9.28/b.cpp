/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-28 20:01:06
 * @FilePath: \ACM\CF\2021.9.28\b.cpp
 * @LastEditTime: 2021-09-28 20:21:39
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

LL a, b;
signed main()
{
    IOS;
    cin >> a >> b;
    LL ans = 1;
    if (abs(b - a) >= 10)
    {
        cout << "0\n";
        return 0;
    }
    for (LL i = a + 1; i <= b; ++i)
    {

        ans *= (i % 10);
        if (ans > 10)
        {
            ans = ans % 10;
        }
    }
    cout << ans % 10 << '\n';
    return 0;
}