/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 21:52:36
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\b.cpp
 * @LastEditTime: 2021-09-07 16:50:18
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

LL qm (LL a, LL b, LL c){
    LL ret = 1 % c;
    while(b){
        if(b & 1)
            ret = ret * a % c;
        a = a * a % c;
        b = b >> 1;
    }
    return ret;
}
const LL mod = 1e9 + 7;
LL mul(LL x, LL y) { return 1LL * x * y % mod; }
LL dec(LL x, LL y) { return x >= y ? x - y : x + mod - y; }
LL add(LL x, LL y) { return x + y >= mod ? x + y - mod : x + y; }
LL pmod(LL x) { return (x + mod) % mod; }

LL inv_fm(LL n, LL p) { return qm(n, p - 2, p); }

const int N = 1e7 + 10;
LL fac[N];
signed main()
{
    IOS;
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        fac[i] = mul(fac[i - 1], i);
    }
    LL fm = 1, fz = 0;
    for (int i = 1; i <= 10; ++i)
    {
        int x;
        cin >> x;
        fm = mul(fm, fac[x]);
        fz += x;
    }
    cout << mul(inv_fm(fm, mod), fac[fz]) << '\n';
    return 0;
}