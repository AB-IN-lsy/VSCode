/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 10:24:52
 * @FilePath: \GPLT\A1024\A1024.cpp
 * @LastEditTime: 2023-01-07 10:37:03
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

#undef int

vector<int> add(vector<int> a, vector<int> b)
{
    int t = 0;
    vector<int> c;
    for (int i = 0; i < SZ(a); ++i)
    {
        int s = a[i] + b[i] + t;
        c.push_back(s % 10);
        t = s / 10;
    }
    if (t)
        c.push_back(t);
    return c;
}

bool check(vector<int> a)
{
    for (int i = 0; i < SZ(a); ++i)
    {
        if (a[i] != a[SZ(a) - 1 - i])
            return false;
    }
    return true;
}

signed main()
{
    IOS;
    string s;
    int k;
    cin >> s >> k;

    vector<int> a;
    for (int i = SZ(s) - 1; i >= 0; --i)
        a.push_back(s[i] - '0');
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (check(a))
            break;
        vector<int> b = a;
        reverse(b.begin(), b.end());
        vector<int> c = add(a, b);
        a = c;
        cnt++;
    }

    for (int i = SZ(a) - 1; i >= 0; --i)
        cout << a[i];
    cout << '\n' << cnt;
    return 0;
}