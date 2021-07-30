/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-29 20:06:08
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-29 20:37:44
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1e6 + 10;
struct Edge
{
    int u, v, w, next;
}edge[N << 2];
int head[N];
int cnt;
void add_edge(int u, int v, int w)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void init(){
    memset(head, -1, sizeof(head));
    cnt = 0;
}
bool vis[N];
int lk[N];
bool dfs(int u)
{
    for(int i = head[u]; i != -1; i = edge[i].next){
        int v = edge[i].v;
        if(!vis[v]){
            vis[v] = 1;
            if(!lk[v] || (dfs(lk[v])) ){
                lk[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int n, m, k;
int a[2010], b[2010];
int main()
{
    IOS;
    init();
    cin >> n >> m >> k;
    LL ans = 0;
    for(int i = 1; i <= n; i ++) cin >> a[i], ans += a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i], ans += b[i];
    for(int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        if(a[x] == b[y]) add_edge(x, y, 1);
    }
    for(int i = 1; i <= n; i ++){
        memset(vis, 0, sizeof vis);
        dfs(i);
    }
    for(int i = 1; i <= n; i ++){
        if(lk[i]) // Assume that lk[i] = x, it means that the edge x -> i
            ans -= b[i]; // because i represent the right set, that is b array
    }
    cout << ans << endl;
    return 0;
}