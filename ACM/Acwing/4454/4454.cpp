/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-10 19:18:03
 * @FilePath: \Acwing\4454\4454.cpp
 * @LastEditTime: 2023-01-10 19:40:12
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
    int n, k, cnt = 0;
    cin >> n >> k;
    unordered_map<int, int> mp;
    for (int i = 1; i <= k; ++i)
    {
        int l, r;
        cin >> l >> r;
        if (!mp.count(r) && r)
            cnt++;
        mp[l] = 1;
    }
    cout << cnt;
    return 0;
}