/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-06 09:30:59
 * @FilePath: \Acwing\4652\4652.cpp
 * @LastEditTime: 2023-01-06 09:47:43
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

// #undef int
int l = 1189, r = 841;

signed main()
{
    IOS;
    string s;
    cin >> s;
    int n = s[1] - '0';
    function<void(int, int &, int &)> dfs = [&](int n, int &l, int &r) {
        if (!n)
            return;
        if (l > r)
            l /= 2, dfs(n - 1, l, r);
        else
            r /= 2, dfs(n - 1, l, r);
    };

    dfs(n, l, r);

    cout << max(l, r) << '\n' << min(l, r);
    return 0;
}