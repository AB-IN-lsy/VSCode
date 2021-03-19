/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-19 21:05:17
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-19 21:20:18
 */
#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define ull                         unsigned long long
#define ld                          long double
#define db                          double
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define MP                          make_pair
#define PB                          emplace_back
#define SZ(X)                       ((int)(X).size())   
#define mset(s, _)                  memset(s, _, sizeof(s))
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl                        "\n"
#define forn(i, l, r)                for (int i = l; i <= r; i++)
typedef pair<int, int>               pii;
typedef pair<ll, ll>                 pll;
const int INF = 0x3f3f3f3f;


namespace AdjacencyListDef{
    const int N = 1e3 + 10;
    typedef struct Node{ //表结点
        int adjvex; //指向的结点下标
        int w; //边权
        struct Node *next;
    }ANode;

    typedef struct VNode{ //头节点
        int data; // 顶点信息
        ANode *firstA;
    }VNode;
    VNode G[N];
    int Vnum, Anum;

    void CreateAdjList(VNode G){
        int n, m = 0;
        cin >> n;
        forn(i, 1, n){
            G[i].data = i;
            G[i].firstA = NULL;
        }
        int a, b, w;
        cin >> a >> b >> w;
        while(a && b){
            ANode *p;
            p = (ANode*)malloc(sizeof(ANode));
            p->adjvex = b;
            p->next = G[i].firstA;
            G[i].firstA = p;
            G[i].w = w;
            m ++;
            cin >> a >> b >> w;
        }
        Vnum = n;
        Anum = m;
    }
}

void solve(){
    
}

int main()
{
    IOS;
    solve();
    return 0;
}