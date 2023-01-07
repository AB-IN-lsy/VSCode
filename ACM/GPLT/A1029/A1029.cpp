/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 17:59:31
 * @FilePath: \GPLT\A1029\A1029.cpp
 * @LastEditTime: 2023-01-07 18:04:48
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

signed main()
{
    IOS;
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    vector<int> c;
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (j == m || (i < n && a[i] < b[j]))
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }
    int sz = SZ(c);
    cout << c[(sz + 1) / 2 - 1] << '\n';

    return 0;
}