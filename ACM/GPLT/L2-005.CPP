/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 12:16:10
 * @FilePath: \ACM\GPLT\L2-005.CPP
 * @LastEditTime: 2022-04-20 20:42:37
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

const int N = 60;
set<int> s[N];
int n;
signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; ++j)
        {
            int x;
            cin >> x;
            s[i].insert(x);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, cnt = 0;
        cin >> a >> b;
        for (auto x : s[a])
        {
            if (s[b].find(x) != s[b].end())
                cnt += 1;
        }
        printf("%.2lf%%\n", 100.0 * cnt / (SZ(s[a]) + SZ(s[b]) - cnt));
    }
    return 0;
}