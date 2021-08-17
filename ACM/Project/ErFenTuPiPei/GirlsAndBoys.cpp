/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-13 13:10:17
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-08-13 13:47:16
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
int main()
{
    int n, x, y, num;
    init();
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        scanf("%d: (%d)", &x, &num);
        for(int i = 1; i <= num; ++ i){
            scanf("%d", &y);
            add_edge(x, y, 1);
        }
        memset(lk, 0, sizeof(lk));
        int ans = 0;
        for(int i = 1; i <= n; ++ i){
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) ans ++;
        }
        printf("%d\n", n - ans / 2);
    }
    return 0;
}