/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-16 08:52:35
 * @FilePath: \Acwing\4507\4507.cpp
 * @LastEditTime: 2022-08-16 09:12:47
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

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> a(N), b(N);
    unordered_map<int, int> odd, even;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
    }
    int ans = 0;
    odd[0]++;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            ans += odd[b[i]];
            odd[b[i]]++;
        }
        else
        {
            ans += even[b[i]];
            even[b[i]]++;
        }
    }
    cout << ans;
    return 0;
}