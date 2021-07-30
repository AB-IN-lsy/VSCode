/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-24 12:39:50
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-29 19:37:29
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

int n, m, a, b, c, d, p, cnt;
const int N = 1e5 + 10;
vector < PII > g[N];
int fa[5010 << 1];

LL mul(LL x, LL y){return 1LL * x * y % p;}
LL dec(LL x, LL y){return x >= y ? x - y : x + p - y;}
LL add(LL x, LL y){return x + y >= p ? x + y - p : x + y;}
LL pp(LL x) {return (x + p) % p;}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}


int main()
{
    IOS;
    cin >> n >> m >> a >> b >> c >> d >> p;
    for(int i = 1; i <= n + m; i ++) fa[i] = i;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            a = (add(add(mul(b, mul(a, a)), mul(a, c)), d)) % p;
            g[a].push_back(MP(i, j));
        }
    }
    LL ans = 0;
    for(int i = 0; i < p; i++){
        for(PII p : g[i]){
            int u = find(p.first);
            int v = find(p.second + n);
            if(u != v){
                cnt ++;
                fa[u] = v;
                ans += i;
            }
            if(cnt == n + m - 1){
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}
