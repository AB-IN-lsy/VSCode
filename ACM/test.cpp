/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-25 10:13:38
 * @FilePath: \ACM\test.cpp
 * @LastEditTime: 2022-03-04 17:04:05
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0)
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define debug(a) cout << "\tdebug:" << a << endl
const double PI = acos(-1.0);
const int mod = 998244353;
const int eps = 1e-8;
const int N = 10 + 2e5;

void slove();
template <typename T> void read(T &x)
{
    x = 0;
    char ch = getchar();
    ll f = 1;
    while (!isdigit(ch))
    {
        if (ch == '-')
            f *= -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    x *= f;
}
template <typename T> void print(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{

    IOS;
    slove();
    return 0;
}

ll a[N];

void slove()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, x;
        cin >> n >> x;
        map<ll, ll> mp;
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        ll cnt = 0;
        for (auto i : mp)
        {
            if (mp[i.first] > 0 && mp[i.first * x] > 0)
            {
                ll minn = min(mp[i.first], mp[i.first * x]);
                mp[i.first] -= minn, mp[i.first * x] -= minn, cnt += 2 * minn;
            }
        }
        cout << n - cnt << endl;
    }
}
