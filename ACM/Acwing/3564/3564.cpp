/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-10 23:00:50
 * @FilePath: \Acwing\3564\3564.cpp
 * @LastEditTime: 2022-08-11 08:51:10
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
    while (T--)
    {
        int y, m, d;
        vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        cin >> y >> m >> d;

        d++;
        if (d > month[m])
        {
            d = 1;
            m++;
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }

        printf("%02lld-%02lld-%02lld\n", y, m, d);
    }
    return 0;
}