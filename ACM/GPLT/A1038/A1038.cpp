/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-09 12:57:42
 * @FilePath: \GPLT\A1038\A1038.cpp
 * @LastEditTime: 2023-01-09 13:20:26
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
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    sort(ALL(s), [&](const string a, const string b) { return a + b < b + a; });

    string res;
    for (int i = 0; i < SZ(s); ++i)
        res += s[i];

    int i = 0;
    while (i < SZ(res) - 1 && res[i] == '0') // 去掉前导0的同时，一定要保留一位，也就是如果最后剩下0，也要保留
        ++i;
    cout << res.substr(i);

    return 0;
}