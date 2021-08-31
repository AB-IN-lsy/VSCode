/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-31 11:08:08
 * @FilePath: \Vscode\ACM\Project\Trie\f.cpp
 * @LastEditTime: 2021-08-31 12:25:57
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

int t, n, a[N], k;
signed main()
{
    IOS;
    cin >> t;
    while(t --){
        init();
        cin >> n >> k;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            
        }
    }
    return 0;
}