/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-26 14:00:53
 * @FilePath: \Vscode\ACM\Project\Trie\Poj3630.cpp
 * @LastEditTime: 2021-08-26 15:25:14
 */
#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<stack>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

namespace Trie{
    const int N = 1e5 + 10;
    int son[N][10], cnt[N], idx;
    void init(){
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
    }
    bool insert(char *s){
        int p = 0, flag = 0;
        for(int i = 0; s[i]; ++ i){
            int u = s[i] - '0';
            if(!son[p][u]) son[p][u] = ++ idx, flag = 1;
            p = son[p][u];
            if(cnt[p]) return false;
        }
        cnt[p] ++;
        return flag;
    }
    int query(char *s){
        int p = 0;
        for(int i = 0; s[i]; ++ i){
            int u = s[i] - '0';
            if(!son[p][u]) return 0;
            p = son[p][u];
        }
        return cnt[p];
    }
}
using namespace Trie;

int t;
char s[N];

signed main()
{
    IOS
    cin >> t;
    while(t --){
        init();
        int n, flag = 0;
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> s;
            if(!insert(s)) flag = 1;
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}