/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 21:52:36
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\b.cpp
 * @LastEditTime: 2021-08-27 23:19:15
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

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
const LL mod = 1e9 + 7;
LL mul(LL x, LL y){return 1LL * x * y % mod;}
LL dec(LL x, LL y){return x >= y ? x - y : x + mod - y;}
LL add(LL x, LL y){return x + y >= mod ? x + y - mod : x + y;}
LL pmod(LL x) {return (x + mod) % mod;}

LL inv_fm(LL n, LL p) { return qm(n, p - 2, p); }

signed main()
{
    IOS;
    LL q = 0;
    for(int i = 1; i <= 10; ++ i){
        int x;
        cin >> x;
        q += x;
    }
    return 0;
}