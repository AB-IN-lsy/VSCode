/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 17:17:47
 * @FilePath: \GPLT\A1027\A1027.cpp
 * @LastEditTime: 2023-01-07 17:35:20
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

string f(int x)
{
    string s;
    while (x)
    {
        int k = x % 13;
        if (k <= 9)
            s += '0' + k;
        else
            s += 'A' + k - 10;
        x /= 13;
    }
    int sz = SZ(s);
    for (int i = 0; i < 2 - sz; ++i)
        s += '0';
    reverse(s.begin(), s.end());
    return s;
}

signed main()
{
    IOS;
    int r, g, b;
    cin >> r >> g >> b;

    cout << "#" << f(r) << f(g) << f(b);

    return 0;
}