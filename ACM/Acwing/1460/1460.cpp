/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-15 15:03:27
 * @FilePath: \Acwing\1460\1460.cpp
 * @LastEditTime: 2023-02-15 15:32:33
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

typedef unsigned long long ULL;
ULL p[N], h[N];
const int P = 13331;
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int n;
string s;

bool check(int x)
{
    unordered_map<int, int> st;
    for (int i = 1; i + x - 1 <= n; ++i)
    {
        int ss = get(i, i + x - 1);
        if (st.count(ss))
            return true;
        st[ss]++;
    }
    return false;
}

signed main()
{
    IOS;
    cin >> n >> s;
    s = " " + s;
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];
    }

    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}