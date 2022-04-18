/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-18 19:55:43
 * @FilePath: \ACM\GPLT\2022MoNi\L1-8.CPP
 * @LastEditTime: 2022-04-18 20:04:34
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
int st[N], vis[N], prime[N];
int cnt;
void init()
{
    for (int i = 2; i < N; ++i)
    {
        if (!st[i])
        {
            prime[cnt++] = i;
            st[i] = 1;
            vis[i] = 1;
        }
        for (int j = 0; i <= N / prime[j]; ++j)
        {
            st[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

signed main()
{
    IOS;
    init();
    int l, r;
    cin >> l >> r;
    int L = lower_bound(prime, prime + cnt, l) - prime;
    int R = upper_bound(prime, prime + cnt, r) - prime - 1;

    int ans = 0;

    for (int i = L; i <= R - 2; ++i)
    {
        for (int j = i + 1; j <= R - 1; ++j)
        {
            for (int k = j + 1; k <= R; ++k)
            {
                int p = prime[i], q = prime[j], r = prime[k];
                if (vis[p * q + r] && vis[q * r + p] && vis[r * p + q])
                {
                    ans += 1;
                }
            }
        }
    }

    cout << ans;
    return 0;
}