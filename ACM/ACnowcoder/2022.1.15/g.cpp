/*
 * @Author: NEFU AB-IN
 * @Date: 2022-01-15 13:26:54
 * @FilePath: \ACM\ACnowcoder\2022.1.15\g.cpp
 * @LastEditTime: 2022-01-15 13:35:46
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

namespace prime_sieve
{
const int N = 1e8 + 5;
int cnt, prime[N], res[N];
bool flag[N];
inline void init()
{
    memset(flag, 1, sizeof(flag));
    flag[0] = flag[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (flag[i])
        {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && 1LL * prime[j] * i <= N; j++)
        {
            flag[prime[j] * i] = 0;
            if (i % prime[j] == 0)
                break;
        }
        res[i] = cnt;
    }
}
} // namespace prime_sieve
using namespace prime_sieve;

signed main()
{
    IOS;
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << res[r] - res[l - 1] << '\n';
    }
    return 0;
}