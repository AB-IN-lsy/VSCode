/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-17 20:28:57
 * @FilePath: \Vscode\ACM\CF\2021.9.17\d.cpp
 * @LastEditTime: 2021-09-17 21:35:27
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

string s;
const int N = 1e7 + 10;
const LL mod = 1e9 + 7;
LL mul(LL x, LL y) { return 1LL * x * y % mod; }
LL dec(LL x, LL y) { return x >= y ? x - y : x + mod - y; }
LL add(LL x, LL y) { return x + y >= mod ? x + y - mod : x + y; }
LL pmod(LL x) { return (x + mod) % mod; }

LL fibs[N];

void fib(int n)
{
    fibs[0] = fibs[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        fibs[i] = add(fibs[i - 1], fibs[i - 2]);
    }
}

signed main()
{
    IOS;
    cin >> s;
    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == 'w' || s[i] == 'm')
        {
            cout << "0\n";
            return 0;
        }
    }
    fib(SZ(s));
    LL u_cnt = 0, n_cnt = 0;
    LL ans = 1;
    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == 'u')
        {
            if (u_cnt)
                u_cnt++;
            else
            {
                ans = mul(ans, fibs[n_cnt]);
                n_cnt = 0;
                u_cnt++;
            }
        }
        else if (s[i] == 'n')
        {
            if (n_cnt)
                n_cnt++;
            else
            {
                ans = mul(ans, fibs[u_cnt]);
                u_cnt = 0;
                n_cnt++;
            }
        }
        else
        {
            ans = mul(ans, fibs[n_cnt]);
            ans = mul(ans, fibs[u_cnt]);
            u_cnt = n_cnt = 0;
        }
    }
    if (u_cnt > 1)
    {
        ans = mul(ans, fibs[u_cnt]);
    }
    if (n_cnt > 1)
    {
        ans = mul(ans, fibs[n_cnt]);
    }
    cout << pmod(ans) << '\n';
    return 0;
}