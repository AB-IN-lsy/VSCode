/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-20 16:00:13
 * @FilePath: \Vscode\ACM\Project\bitset\StrangeBulbs.cpp
 * @LastEditTime: 2021-08-20 16:00:37
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

const int N = 4e4 + 10;
struct Edge
{
    int u, v, ne;
}e[N << 2];
int h[N];
int cnt;
void add(int u, int v)
{
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].ne = h[u];
    h[u] = cnt++;
}
void init(){
    memset(h, -1, sizeof(h));
    cnt = 0;
}
int n, m, u, v, ans;
int deg[N];
bitset <N> dp[N];

signed main()
{
    IOS;
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; ++ i){
        cin >> u >> v;
        add(u, v);
        deg[v] ++;
    }
    queue <int> q;
    for(int i = 1; i <= n; ++ i){
        if(!deg[i]) {
            q.push(i);
            dp[i][i] = 1; //init
            ans ++;
        }
    }
    while(q.size()){
        int tp = q.front();
        q.pop();
        for(int i = h[tp]; ~i; i = e[i].ne){
            v = e[i].v;
            dp[v] |= dp[tp];
            if(!--deg[v]){
                q.push(v);
                if(dp[v].count() & 1){
                    dp[v][v] = 1;
                    ans ++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}