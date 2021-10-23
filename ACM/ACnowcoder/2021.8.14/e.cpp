/*
 * @Description: E
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-14 12:54:43
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-08-14 13:58:31
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

const int N = 1e5 + 10;
unordered_map <int, int> tmp;
int vis[N];

struct Edge
{
    int u, v, next;
}edge[N << 2];

int head[N];
int cnt;
void add_edge(int u, int v)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void init(){
    memset(head, -1, sizeof(head));
    cnt = 0;
}

int n, q;
int mx = 0;

void bfs(int x, int l, int r, int ct){
    if(tmp[x] < l || tmp[x] > r) return;
    vis[x] = 1;
    for(int i = head[x]; ~i; i = edge[i].next){
        int v = edge[i].v;
        if(tmp[v] >= l && tmp[v] <= r && !vis[v]){
            mx = max(mx, ct + 1);
            bfs(v, l, r, ct + 1);
        }
    }
}
int main()
{
    IOS;
    init();
    cin >> n;
    for(int i = 1; i <= n - 1; ++ i){
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    for(int i = 1; i <= n; ++ i) cin >> tmp[i];
    cin >> q;
    for(int i = 1; i <= q; ++ i){
        int l, r, x;
        cin >> x >> l >> r;
        if(tmp[x] < l || tmp[x] > r) {
            cout << "0\n";
            continue;
        }
        mx = 1;
        memset(vis, 0, sizeof(vis));
        bfs(x, l, r, 1);
        cout << mx << '\n';
    }
    return 0;
}