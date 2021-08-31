/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 10:11:04
 * @FilePath: \Vscode\ACM\Project\Trie\poj3764.cpp
 * @LastEditTime: 2021-08-27 11:10:44
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

const int N = 1e6 + 10;
struct Edge
{
    int u, v, w, ne;
}e[N << 2];
int h[N];
int cnt;
void add(int u, int v, int w)
{
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].ne = h[u];
    h[u] = cnt++;
}
void init(){
    memset(h, -1, sizeof(h));
    cnt = 0;
}
namespace Trie01{
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
        return val[p] ^ x;
    }
}
using namespace Trie01;
int n, a[N], u, v, w;

void dfs(int u, int fa, int dis){
    a[u] = dis;
    for(int i = h[u]; ~i; i = e[i].ne){
        int vv = e[i].v;
        int ww = e[i].w;
        if(vv == fa) continue;
        dfs(vv, u, dis ^ ww);
    }
}

signed main()
{
    ::init();
    cin >> n;
    for(int i = 1; i <= n - 1; ++ i){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 0, 0);
    for(int i = 1; i <= n; ++ i){
        insert(a[i]);
    }
    int ans = a[1] ^ a[2];
    for(int i = 1; i <= n; ++ i){
        ans = max(ans, query(a[i]));
    }
    cout << ans << '\n';
    return 0;
}