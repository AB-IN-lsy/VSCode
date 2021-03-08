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
#define ll long long
#define ull unsigned long long
#define ld long double
#define db double
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define rep1(i, a, n) for (int i = a; i < n; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define per1(i ,a, n) for (int i = a; i > n; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define lowbit(x) ((x) &-(x))
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
namespace spfa_{
    const int N = 5e4 + 10;
    const int inf = 0x3f3f3f3f;
    struct Edge
    {
        int u, v, w, next;
    }edge[N << 2];

    int head[N];
    int cnt;

    void init(){
        memset(head, -1, sizeof(head));
        cnt = 0;
    }

    void add_edge(int u, int v, int w)
    {
        edge[cnt].u = u;
        edge[cnt].v = v;
        edge[cnt].w = w;
        edge[cnt].next = head[u];
        head[u] = cnt++;
    }
    int dis[N], vis[N], number[N], n;

    int spfa(int s, int d[]){
        queue < int > q;
        mset(vis, 0);
        mset(number, 0);
        for(int i = 0; i <= n; i++) d[i] = -inf;
        d[s] = 0;
        vis[s] = 1;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for(int i = head[u]; i != -1; i = edge[i].next){
                int v = edge[i].v, w = edge[i].w;
                if(d[v] < d[u] + w){
                    d[v] = d[u] + w;
                    if( !vis[v] ){
                        vis[v] = 1;
                        q.push(v);
                        number[v] ++;
                        if(number[v] == n) return 0;
                    }
                }
            }
        }
        return 1;
    }
}
using namespace spfa_;
int t, a, b, c;

int main()
{
    init();
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++){
        scanf("%d%d%d", &a, &b, &c);
        a ++;
        b ++;
        add_edge(a - 1, b, c);
        n = max(n, b);
    }
    for(int i = 1; i <= n; i ++){
        add_edge(i - 1, i, 0);
        add_edge(i, i - 1, -1);
    }
    spfa(0, dis);
    printf("%d\n", dis[n]);
    return 0;
}