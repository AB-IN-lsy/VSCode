/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-20 01:58:19
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.14\I.cpp
 * @LastEditTime: 2021-08-20 14:22:38
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

signed main()
{
    IOS;
    LL n, x, y, w;
    cin >> n >> w >> x >> y;
    cout << n * x * qm(y, 998244353 - 2, 998244353) % 998244353 << '\n';  
    return 0;
}