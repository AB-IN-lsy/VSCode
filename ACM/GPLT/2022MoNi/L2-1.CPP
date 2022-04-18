/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-18 20:20:23
 * @FilePath: \ACM\GPLT\2022MoNi\L2-1.CPP
 * @LastEditTime: 2022-04-18 20:25:33
 */
/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-18 20:17:05
 * @FilePath: \ACM\GPLT\2022MoNi\L2-1.CPP
 * @LastEditTime: 2022-04-18 20:18:19
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
const int N = 1e5 + 10;
string a[N];

unordered_map<string, int> mp;

signed main()
{
    IOS;
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int point = 1;
    for (int i = 1; i <= n / s; ++i)
    {
        stack<int> S;
        for (int j = 1; j <= s; ++j)
        {
            int x;
            cin >> x;
            S.push(x);
        }
        while (S.size())
        {
            int top = S.top();
            S.pop();
            mp[a[point++]] = top;
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        string t;
        cin >> t;
        if (mp[t])
            cout << mp[t] << '\n';
        else
            cout << "Wrong Number\n";
    }
    return 0;
}