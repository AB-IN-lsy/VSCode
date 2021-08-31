/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 02:41:04
 * @FilePath: \Vscode\ACM\Project\Trie\SecretMessage.cpp
 * @LastEditTime: 2021-08-27 10:10:54
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

namespace Trie{
    const int N = 2e6 + 10;
    int son[N][2], cnt[N], idx, ans[N];
    char s[N];
    void init(){
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
    }
    void insert(char *s){
        int p = 0;
        for(int i = 0; s[i]; ++ i){
            int u = s[i] - '0';
            if(!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
            ans[p] ++;
        }
        cnt[p] ++;
    }
    int query(char *s){
        int p = 0, tot = 0, flag = 0;
        for(int i = 0; s[i]; ++ i){
            int u = s[i] - '0';
            if(!son[p][u]) {
                flag = 1;
                break;
            }
            p = son[p][u];
            tot += cnt[p];
        }
        if(!flag) tot += ans[p] - cnt[p];
        return tot;
    }
}
using namespace Trie;

int n, m;
signed main()
{
    IOS;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        int k, idx = 0;
        cin >> k;
        for(int j = 1; j <= k; ++ j){
            char x;
            cin >> x;
            s[idx ++] = x;
        }
        s[idx] = '\0';
        insert(s);
    }
    for(int i = 1; i <= m; ++ i){
        int k, idx = 0;
        cin >> k;
        for(int j = 1; j <= k; ++ j){
            char x;
            cin >> x;
            s[idx ++] = x;
        }
        s[idx] = '\0';
        cout << query(s) << '\n';
    }
    return 0;
}