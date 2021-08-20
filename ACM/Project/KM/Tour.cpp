/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-19 16:06:12
 * @FilePath: \Vscode\ACM\Project\KM\Tour.cpp
 * @LastEditTime: 2021-08-19 16:12:01
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

namespace KM{
    const int N = 1e4 + 10;
    int n, ex_L[N], ex_R[N], match[N], slack[N], w[N][N];
    bool vis_L[N], vis_R[N];
    const int INF = 0x3f3f3f3f;
    
    bool dfs(int u){
        vis_L[u] = true;
        for(int v = 1; v <= n; ++ v){
            if(vis_R[v]) continue;
            int gap = ex_L[u] + ex_R[v] - w[u][v];
            if(!gap){
                vis_R[v] = true;
                if(!match[v] || dfs(match[v])){
                    match[v] = u;
                    return true;
                }
            }
            else{
                slack[v] = min(slack[v], gap);
            }
        }
        return false;
    }

    int km(){
        memset(match, 0, sizeof match);
        memset(ex_R, 0, sizeof ex_R);
        for(int i = 1; i <= n; ++ i){
            ex_L[i] = w[i][1];
            for(int j = 1; j <= n; ++ j){
                ex_L[i] = max(ex_L[i], w[i][j]);
            }
        }
        for(int i = 1; i <= n; ++ i){
            memset(slack, 0x3f, sizeof slack);
            while(true){
                memset(vis_L, false, sizeof vis_L);
                memset(vis_R, false, sizeof vis_R);
                if(dfs(i)) break;
                int d = INF;
                for(int j = 1; j <= n; ++ j) 
                    if (!vis_R[j]) d = min(d, slack[j]);
                for(int j = 1; j <= n; ++ j){
                    if(vis_L[j]) ex_L[j] -= d;
                    if(vis_R[j]) ex_R[j] += d;
                    else slack[j] -= d;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++ i){
            if(match[i]) ans += w[match[i]][i];
        }
        return ans;
    }
}
using namespace KM;

signed main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        int m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
                w[i][j] = -INF;
        for(int i = 1; i <= m; ++ i){
            int u, v, x;
            cin >> u >> v >> x;
            w[u][v] = max(w[u][v], -x);
        }
        cout << -km() << '\n';
    }
    return 0;
}