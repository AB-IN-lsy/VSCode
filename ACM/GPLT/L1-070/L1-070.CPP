/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-22 16:23:40
 * @FilePath: \ACM\GPLT\L1-070.CPP
 * @LastEditTime: 2022-04-22 19:13:15
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
    int cnt = 0;
    vector<int> ans;
    string s;
    string t = "chi1 huo3 guo1";
    while (getline(cin, s), s != ".")
    {
        cnt += 1;
        if (strstr(s.c_str(), t.c_str()))
        {
            ans.push_back(cnt);
        }
    }
    cout << cnt << '\n';
    if (SZ(ans))
        cout << ans[0] << " " << SZ(ans) << '\n';
    else
        cout << "-_-#\n";
    return 0;
}