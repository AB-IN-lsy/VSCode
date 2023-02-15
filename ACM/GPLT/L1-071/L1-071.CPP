/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-22 16:35:44
 * @FilePath: \ACM\GPLT\L1-071.CPP
 * @LastEditTime: 2022-04-22 16:37:56
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

int n, m;

signed main()
{
    IOS;
    cin >> n >> m;
    int base = 1 << n;
    for (int i = 1; i <= m; ++i)
    {
        string s;
        cin >> s;
        int ans = 1;
        for (auto i : s)
        {
            if (i == 'y')
                ans = ans << 1;
            else
                ans = ans << 1 | 1;
        }
        ans -= base - 1;
        cout << ans << '\n';
    }
    return 0;
}