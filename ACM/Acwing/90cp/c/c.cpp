/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-12 18:35:26
 * @FilePath: \Acwing\90cp\c\c.cpp
 * @LastEditTime: 2023-02-12 20:07:41
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

const int N = 100, INF = 0x3f3f3f3f;
int ne[N];

signed main()
{
    IOS;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    s = " " + s;

    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
    }

    int l = ne[n];
    string p = s.substr(l + 1, n - l);
    cout << s.substr(1);
    for (int i = 1; i <= k - 1; ++i)
    {
        cout << p;
    }
    return 0;
}