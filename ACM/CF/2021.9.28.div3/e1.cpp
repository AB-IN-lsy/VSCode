/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-28 23:39:42
 * @FilePath: \ACM\CF\2021.9.28.div3\e1.cpp
 * @LastEditTime: 2021-09-29 16:36:31
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
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

void solve()
{
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            q.emplace_back(x);
            continue;
        }
        if (*q.begin() >= x)
            q.emplace_front(x);
        else
            q.emplace_back(x);
    }
    for (auto i : q)
        cout << i << " ";
    cout << '\n';
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