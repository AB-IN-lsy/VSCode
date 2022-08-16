/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-13 19:19:45
 * @FilePath: \64cp\B\B.cpp
 * @LastEditTime: 2022-08-13 19:59:58
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
    vector<int> a(N), b(N), c[N];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
    }

    for (int i = 0; i <= n; ++i)
        c[b[i]].push_back(i);
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (SZ(c[i]) > 1)
        {
            for (int j = 0; j < SZ(c[i]); ++j)
            {
                for (int k = j + 1; k < SZ(c[i]); ++k)
                {
                    if ((c[i][k] - c[i][j]) % 2 == 0)
                        ans++;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}