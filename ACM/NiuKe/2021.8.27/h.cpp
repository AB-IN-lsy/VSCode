/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 21:43:30
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\h.cpp
 * @LastEditTime: 2021-09-05 20:59:24
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 5e7 + 10;
int flag[N], prime[N], cnt, dp[N << 1];

void init()
{
    memset(flag, 1, sizeof flag);
    flag[0] = flag[1] = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (flag[i])
        {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= N; ++j)
        {
            flag[i * prime[j]] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
}

signed main()
{
    IOS
    init();
    int t, n = 1e8;
    cin >> t;
    for(int i = 1; prime[i] * prime[i] <= n; ++ i){
        for(int j = i; prime[i] * prime[j] <= n; ++ j){
            dp[prime[i] * prime[j]] = 1;
        }
    }
    for(int i = 1; i <= n; ++ i){
        dp[i] += dp[i - 1];
    }
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << '\n';
    }
    return 0;
}