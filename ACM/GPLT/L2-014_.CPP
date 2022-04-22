/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-21 11:37:00
 * @FilePath: \ACM\GPLT\L2-014_.CPP
 * @LastEditTime: 2022-04-21 11:40:30
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

set<int> s;
int n;

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (s.upper_bound(x) != s.end())
        {
            s.erase(s.upper_bound(x));
        }
        s.insert(x);
    }
    cout << SZ(s);
    return 0;
}