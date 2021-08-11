/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-09 15:26:09
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-09 21:56:42
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

int main()
{
    IOS;
    int n, m, k, a, l, x, y, z, sum = 0, ans = 1;
    cin >> n >> m >> k >> a >> l;
    for(int i = 1; i <= k; i ++){
        cin >> x >> y >> z;
        if(x == 0) continue;
        ans *= ((z - y) * inv_fm(z, 4933)) % 4933;
        sum += x;
    }
    if(sum != l) cout <<"0\n";
    else cout << (a + ans) % 4933 << '\n';

    return 0;
}