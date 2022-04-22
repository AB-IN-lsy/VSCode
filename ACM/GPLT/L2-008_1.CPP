/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 18:04:25
 * @FilePath: \ACM\GPLT\L2-008_1.CPP
 * @LastEditTime: 2022-04-20 19:24:01
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

signed main()
{
    IOS;
    string s;
    getline(cin, s);
    int ans = 1;
    for (int i = 0; i < SZ(s); ++i)
    {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < SZ(s) && s[l] == s[r])
            l--, r++;
        ans = max(ans, r - l - 1);

        l = i, r = i + 1;
        while (l >= 0 && r < SZ(s) && s[l] == s[r])
            l--, r++;
        ans = max(ans, r - l - 1);
    }
    cout << ans;
    return 0;
}