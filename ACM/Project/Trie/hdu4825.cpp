/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-26 16:40:07
 * @FilePath: \Vscode\ACM\Project\Trie\hdu4825.cpp
 * @LastEditTime: 2021-08-26 22:54:39
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

namespace Trie01{
    const int N = 1e5 + 10;
    int son[N * 32][2], val[N * 32], idx;
    void init(){
        idx = 0;
        son[0][0] = son[0][1] = 0;
    }
    void insert(int x){
        int p = 0;
        for(int i = 31; i >= 0; -- i){
            int u = (x >> i) & 1;
            if(!son[p][u]){
                son[p][u] = ++ idx;
                p = son[p][u];
                son[p][0] = son[p][1] = 0;
            }
            else p = son[p][u];
        }
        val[p] = x;
    }
    int query(int x){
        int p = 0;
        for(int i = 31; i >= 0; -- i){
            int u = (x >> i) & 1;
            if(son[p][u ^ 1]) p = son[p][u ^ 1];
            else p = son[p][u];
        }
        return val[p];
    }
}
using namespace Trie01;

int t, n, m, x;
signed main()
{
    IOS
    while(~scanf("%d", &t)){
        for(int j = 1; j <= t; ++ j){
            init();
            scanf("%d%d", &n, &m);
            for(int i = 1; i <= n; ++ i){
                scanf("%d", &x);
                insert(x);
            }
            printf("Case #%d:\n", j);
            for(int i = 1; i <= m; ++ i){
                scanf("%d", &x);
                printf("%d\n", query(x));
            }
        }
    }
    return 0;
}