/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-23 22:49:26
 * @FilePath: \Acwing\830\830.cpp
 * @LastEditTime: 2023-02-23 22:53:13
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    int n;
    cin >> n;
    stack<int> stk;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        while (SZ(stk) && stk.top() >= x)
            stk.pop();
        if (SZ(stk))
            cout << stk.top() << " ";
        else
            cout << "-1 ";
        stk.push(x);
    }
    return 0;
}