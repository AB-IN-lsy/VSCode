/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-18 16:25:25
 * @FilePath: \Vscode\ACM\Project\KM\J.cpp
 * @LastEditTime: 2021-08-19 14:08:47
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((LL)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<LL , LL>               PII;

namespace KM{
    const LL N = 1e4 + 10;
    LL n, ex_L[N], ex_R[N], match[N], slack[N], w[N][N];
    bool vis_L[N], vis_R[N];
    const LL INF = 0x3f3f3f3f;
    
    bool dfs(LL u){
        vis_L[u] = true;
        for(LL v = 1; v <= n; ++ v){
            if(vis_R[v]) continue;
            LL gap = ex_L[u] + ex_R[v] - w[u][v];
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

    LL km(){
        memset(match, 0, sizeof match);
        memset(ex_R, 0, sizeof ex_R);
        for(LL i = 1; i <= n; ++ i){
            ex_L[i] = w[i][1];
            for(LL j = 1; j <= n; ++ j){
                ex_L[i] = max(ex_L[i], w[i][j]);
            }
        }
        for(LL i = 1; i <= n; ++ i){
            memset(slack, 0x3f, sizeof slack);
            while(true){
                memset(vis_L, false, sizeof vis_L);
                memset(vis_R, false, sizeof vis_R);
                if(dfs(i)) break;
                LL d = INF;
                for(LL j = 1; j <= n; ++ j) 
                    if (!vis_R[j]) d = min(d, slack[j]);
                for(LL j = 1; j <= n; ++ j){
                    if(vis_L[j]) ex_L[j] -= d;
                    if(vis_R[j]) ex_R[j] += d;
                    else slack[j] -= d;
                }
            }
        }
        LL ans = 0;
        for(LL i = 1; i <= n; ++ i){
            if(match[i]) ans += w[match[i]][i];
        }
        return ans;
    }
}
using namespace KM;


LL ans;

LL dis(LL X, LL Y, LL Z){
    return X * X + Y * Y + Z * Z;
}

signed main()
{
    IOS;
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        LL x, y, z, v;
        cin >> x >> y >> z >> v;
        for(int j = 1; j <= n; ++ j){
            w[i][j] -= dis(x, y, z + (j - 1) * v);
        }
    }
    cout << -km() << '\n';
    return 0;
}
