/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-24 12:39:50
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-24 12:50:39
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

int n, m, a, b, c, d, p;
LL g[5010][5010];
const int N = 3E7;
LL A[N];

LL mul(LL x, LL y){return 1LL * x * y % p;}
LL dec(LL x, LL y){return x >= y ? x - y : x + p - y;}
LL add(LL x, LL y){return x + y >= p ? x + y - p : x + y;}
LL pp(LL x) {return (x + p) % p;}

int main()
{
    IOS;
    cin >> n >> m >> a >> b >> c >> d >> p;
    A[0] = a;
    for(int i = 0; i <= N; i ++){
        A[i + 1] = (add ( add(mul(b, mul(A[i], A[i])), mul(A[i], c)) , d)) % p;
    }
    return 0;
}
