/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-06-18 22:18:16
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

LL inv_fm(LL a, LL n) { return qm(a, n - 2, n); }

const LL mod = 1e9 + 7;
LL mul(LL x, LL y){return 1LL * x * y % mod;}
LL dec(LL x, LL y){return x >= y ? x - y : x + mod - y;}
LL add(LL x, LL y){return x + y >= mod ? x + y - mod : x + y;}
LL pmod(LL x) {return (x + mod) % mod;}

int main()
{
  IOS;
  LL n;
  cin >> n;
  LL ans = 1;
  for(int i = 1; i <= n; i ++){
    LL p = 2 * i - 1 - n;
    if(p < 0){
      LL p1 = qm(i, -p, mod);
      ans = mul(ans, inv_fm(p1, mod));
    }
    else{
      ans = mul(ans, qm(i, p, mod));
    }
  }
  cout << pmod(ans) << '\n';
  return 0;
}