/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-07 14:22:28
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-07 14:22:29
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

map <int, int> m1;
map <int, int> m2;

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

int main()
{
    IOS;
    init();
    int n, t;
    cin >> t;

    while(t --){
        m1.clear();
        m2.clear();
        cin >> n;
        for(int i = 1; i <= n - 1; i ++){
            int u, v;
            add_edge(u, v, 1);
        }
    }    
    return 0;
}