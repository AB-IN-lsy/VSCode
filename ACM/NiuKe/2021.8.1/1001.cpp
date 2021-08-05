/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-01 14:03:21
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-01 14:20:07
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const LL mod = 998244353;
ULL mul(LL x, LL y){return 1ULL * x * y % mod;}
LL dec(LL x, LL y){return x >= y ? x - y : x + mod - y;}
LL add(LL x, LL y){return x + y >= mod ? x + y - mod : x + y;}
LL pmod(LL x) {return (x + mod) % mod;}

namespace q_pow{
    LL q (LL a, LL b){
        LL ret = 1;
        while(b){
            if(b & 1)
                ret = ret * a;
            a = a * a;
            b = b >> 1;
        }
        return ret;
    }
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
}
using namespace q_pow;

int main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        ULL a, b, k;
        cin >> a >> b >> k;
        ULL m = qm(2, (k / 2), mod);
        if(k & 1) cout << mul(m, add(a, b)) << " " << mul(m, dec(a, b)) << endl;
        else cout << mul(m, a) << " " << mul(m, b) << endl;
    }
    return 0;
}