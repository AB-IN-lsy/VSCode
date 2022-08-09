/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-29 22:54:45
 * @FilePath: \Acwing\3559\3559.1.cpp
 * @LastEditTime: 2022-07-29 22:57:34
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve()
{

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }
    int cnt = 0;
    while (SZ(q))
    {
        auto t = q.front();
        q.pop();
        cnt++;
        if (cnt == 3)
        {
            cnt = 0;
            cout << t << " ";
            continue;
        }
        q.push(t);
    }
    cout << '\n';
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}