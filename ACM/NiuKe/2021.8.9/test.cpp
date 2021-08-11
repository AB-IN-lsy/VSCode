/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-11 10:50:16
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-11 15:20:49
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

LL p;
const LL N = 1e6 + 10;
LL fac[N], finv[N];
LL mul(LL x, LL y){return 1LL * x * y % p;}
LL dec(LL x, LL y){return x >= y ? x - y : x + p - y;}
LL add(LL x, LL y){return x + y >= p ? x + y - p : x + y;}
LL pp(LL x) {return (x + p) % p;}

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

void init(){
    fac[0] = 1;
    for(int i = 1; i <= p; ++ i){
        fac[i] = mul(fac[i - 1], i); 
    }
}
LL inv_fm(LL n, LL p) { return qm(n, p - 2, p); }

LL C(LL n, LL m, LL p){
    return m > n ? 0 : mul(fac[n], mul(inv_fm(fac[m], p), inv_fm(fac[n - m], p)));
}


LL lucas(LL n, LL m, LL p){
    if(n < m) return 0;
    if(n == m || m == 0) return 1;
    else{
        return (C(n % p, m % p, p) * lucas(n / p, m / p, p));
    }
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        LL n, m;
        cin >> n >> m >> p;
        init();
        cout << lucas(n + m, m, p) << '\n';
    }
    return 0;
}