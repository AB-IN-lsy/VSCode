/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 19:35:12
 * @FilePath: \GPLT\A1031\A1031.cpp
 * @LastEditTime: 2023-01-07 19:41:49
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

// #undef int

signed main()
{
    IOS;
    string s;
    cin >> s;

    int sz = SZ(s);
    int n1 = (sz + 2) / 3, n3 = (sz + 2) / 3, n2 = sz - n1 - n3 + 2;

    for (int i = 0; i < n1 - 1; ++i)
    {
        cout << s[i];
        for (int j = 0; j < n2 - 2; ++j)
            cout << " ";
        cout << s[sz - i - 1] << '\n';
    }
    int i = n1 - 1;
    while (true)
    {
        cout << s[i++];
        if (i == n1 + n2 - 1)
            break;
    }

    return 0;
}