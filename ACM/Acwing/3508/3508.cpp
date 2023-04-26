/*
 * @Author: NEFU AB-IN
 * @Date: 2023-04-20 16:41:03
 * @FilePath: \Acwing\3508\3508.cpp
 * @LastEditTime: 2023-04-20 17:45:37
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define ULL unsigned long long

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f, P = 13331;
ULL hs[N], ps[N], ht[N], pt[N];
string s, t;

ULL gets(int l, int r)
{
    return hs[r] - hs[l - 1] * ps[r - l + 1];
}
ULL gett(int l, int r)
{
    return ht[r] - ht[l - 1] * pt[r - l + 1];
}

bool check(int x)
{
    unordered_set<int> us;
    for (int i = 1; i + x - 1 < SZ(s); ++i)
    {
        us.insert(gets(i, i + x - 1));
    }
    for (int i = 1; i + x - 1 < SZ(t); ++i)
    {
        if (us.count(gett(i, i + x - 1)))
            return true;
    }
    return false;
}

signed main()
{
    IOS;

    cin >> s >> t;

    s = " " + s;
    t = " " + t;

    for (int i = 1; i < SZ(s); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            s[i] = '#';
    }

    for (int i = 1; i < SZ(t); ++i)
    {
        if (t[i] >= '0' && t[i] <= '9')
            t[i] = '$';
    }

    ps[0] = pt[0] = 1;
    for (int i = 1; i < SZ(s); ++i)
    {
        ps[i] = ps[i - 1] * P;
        hs[i] = hs[i - 1] * P + s[i];
    }

    for (int i = 1; i < SZ(t); ++i)
    {
        pt[i] = pt[i - 1] * P;
        ht[i] = ht[i - 1] * P + t[i];
    }

    int l = 0, r = min(SZ(s), SZ(t));
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}
