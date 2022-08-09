/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-07 20:13:36
 * @FilePath: \Acwing\3531\3531.cpp
 * @LastEditTime: 2022-08-07 21:36:05
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
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int res = 0;
    while (SZ(q) > 1)
    {
        auto t1 = q.top();
        q.pop();
        auto t2 = q.top();
        q.pop();

        res += t1 + t2;
        q.push(t1 + t2);
    }

    cout << res << '\n';
    return 0;
}