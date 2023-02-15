/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-12 18:35:26
 * @FilePath: \Acwing\90cp\a\a.cpp
 * @LastEditTime: 2023-02-12 18:37:09
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
    string s;
    cin >> s;

    if (islower(s[0]))
        s[0] = s[0] + 'A' - 'a';

    cout << s;
    return 0;
}