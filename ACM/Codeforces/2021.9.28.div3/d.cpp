/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-28 23:44:08
 * @FilePath: \ACM\CF\2021.9.28.div3\d.cpp
 * @LastEditTime: 2021-09-29 15:45:11
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    priority_queue<PII, vector<PII>> q;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        q.push(MP(x, i));
    }
    deque<PII> Q;
    while (q.size() > 1)
    {
        PII x1 = q.top();
        q.pop();
        PII x2 = q.top();
        q.pop();
        if (x1.first == 0 || x2.first == 0)
        {
            break;
        }
        x1.first--;
        x2.first--;
        Q.emplace_front(MP(x1.second, x2.second));
        if (x1.first)
            q.push(x1);
        if (x2.first)
            q.push(x2);
    }
    cout << Q.size() << '\n';
    for (auto i : Q)
    {
        cout << i.first << " " << i.second << '\n';
    }
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}