/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-09 15:44:18
 * @FilePath: \ACM\CF\2021.10.9\e.cpp
 * @LastEditTime: 2021-10-09 15:46:10
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
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
    int n;
    cin >> n;
    int mn = INF;
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        mn = min(b / a, mn);
    }
    cout << mn << '\n';
    return 0;
}