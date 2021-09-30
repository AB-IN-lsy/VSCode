/*
 * @Author: 0iq
 * @LastEditTime: 2021-09-30 20:16:26
 * @CSDN blog: https://blog.csdn.net/acm_durante
 * @E-mail: 1055323152@qq.com
 * @ProbTitle: 
 */
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define lowbit(x) ((x) & -(x))
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
#define mem(a, b) memset(a, b, sizeof(a))
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
template <class T>
inline void read(T &res)
{
    char c;
    T flag = 1;
    while ((c = getchar()) < '0' || c > '9')
        if (c == '-')
            flag = -1;
    res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        res = res * 10 + c - '0';
    res *= flag;
}
bool solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1 || m > (n * (n - 1)) / 2)
        return 0;
    ll minn = 0;
    if (m == (n * (n - 1)) / 2)
        minn = 1;
    else
        minn = 2;
    if (n == 1)
        minn = 0;
    if (minn <= k - 2)
        return 1;
    return 0;
}
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}