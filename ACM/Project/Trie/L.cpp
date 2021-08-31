/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 01:01:30
 * @FilePath: \Vscode\ACM\Project\Trie\L.cpp
 * @LastEditTime: 2021-08-27 01:34:09
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
    const int N = 2e6 + 20;
    int n, m, dp[N];
    int son[N][26], cnt[N], idx;
    char s[N];
    void init(){
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
    }
    void insert(char *s){
        int p = 0;
        for(int i = 0; s[i]; ++ i){
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
        }
        cnt[p] ++;
    }
    void query(int x){ // the searching start index of string s
        int p = 0;
        for(int i = x; s[i]; ++ i){
            int u = s[i] - 'a';
            if(!son[p][u]) break;
            p = son[p][u];
            if(cnt[p]) dp[i] = 1; // explain there exists a word's end, so next time
                                  // dp will call this function, the param is id plus one
        }
    }
}
using namespace Trie;

signed main()
{
    IOS;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> s;
        insert(s);        
    }
    for(int j = 1; j <= m; ++ j){
        memset(dp, 0, sizeof dp);
        cin >> s + 1;
        dp[0] = 1; // init
        for(int i = 0; s[i]; ++ i){
            if(dp[i]) query(i + 1);
        }
        for(int i = strlen(s); i >= 0; -- i){
            // from end to start, in order to gain the max number depend on
            // greedy thought, and has made sure if there r not exist a solution
            // then output 0 because of dp[0] = 1
            if(dp[i]){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}