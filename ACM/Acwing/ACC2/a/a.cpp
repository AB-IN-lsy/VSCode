/*
 * @Author: NEFU AB-IN
 * @Date: 2023-04-02 18:49:27
 * @FilePath: \Acwing\ACC2\a\a.cpp
 * @LastEditTime: 2023-04-02 19:15:54
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
    int n, ans = 0;
    cin >> n;
    while (n)
    {
        if (n % 2 == 0)
            n /= 2;
        else
        {
            n--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}