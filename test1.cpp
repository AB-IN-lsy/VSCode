#include<bits/stdc++.h>
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 10;

int n;
int son[N], st[N];

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

int dfs(int u){
    int ans = 0;
    son[u] = -1;
    for(int i = head[u]; ~i; i = edge[i].next){
        int j = edge[i].v;
        int d = dfs(j);
        if(ans < d) ans = d, son[u] = j;
        else if(ans == d && j < son[u]) son[u] = j;
    }
    return ans + 1;
}

int main()
{
    IOS;
    init();
    cin >> n;
    for(int i = 0; i < n; i ++){
        int tmp;
        cin >> tmp;
        while(tmp --){
            int x;
            cin >> x;
            add_edge(i, x, 0);
            st[x] = 1;
        }
    }
    int root = 0;
    while(st[root]) root ++;
    cout << dfs(root) << endl;
    cout << root;
    while(son[root] != -1){
        cout << " " << son[root];
        root = son[root]; 
    }
    return 0;
}