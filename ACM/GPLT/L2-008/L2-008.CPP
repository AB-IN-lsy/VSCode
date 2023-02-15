/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 17:29:32
 * @FilePath: \ACM\GPLT\L2-008.CPP
 * @LastEditTime: 2022-04-20 17:53:50
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

const int N = 1010;
int dp[N][N];

signed main()
{
    IOS;
    string s, t;
    getline(cin, s);
    t = s;
    reverse(t.begin(), t.end());

    s = " " + s;
    t = " " + t;
    for (int i = 1; i < SZ(s); ++i)
    {
        for (int j = 1; j < SZ(t); ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i] == t[j])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[SZ(s) - 1][SZ(s) - 1];

    return 0;
}