/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-09 19:15:51
 * @FilePath: \GPLT\A1041\A1041.cpp
 * @LastEditTime: 2023-01-09 19:18:16
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
    unordered_map<int, int> mp;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], mp[a[i]]++;

    for (auto &num : a)
    {
        if (mp[num] == 1)
        {
            cout << num;
            return 0;
        }
    }
    cout << "None";
    return 0;
}