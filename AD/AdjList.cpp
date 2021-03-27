/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-19 21:05:17
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-20 16:09:01
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
    void CreateAdjList(VNode G[], int &n, int &m){
        m = 0;
        cin >> n;
        forn(i, 1, n){ //init
            G[i].data = i;
            G[i].firstA = NULL;
        }
        int a, b, w;
        cin >> a >> b >> w;
        while(a && b){ //尾插法
            ANode *p;
            p = (ANode*)malloc(sizeof(ANode));
            p->adjvex = b;
            p->w = w;
            p->next = G[a].firstA;
            G[a].firstA = p;
            m ++;
            cin >> a >> b >> w;
        }
    }

    void CreateReverseAdjList(VNode G[], int &n, int &m){
        m = 0;
        cin >> n;
        forn(i, 1, n){ //init
            G[i].data = i;
            G[i].firstA = NULL;
        }
        int a, b, w;
        cin >> a >> b >> w;
        while(a && b){ //尾插法
            ANode *p;
            p = (ANode*)malloc(sizeof(ANode));
            p->adjvex = a;
            p->w = w;
            p->next = G[b].firstA;
            G[b].firstA = p;
            m ++;
            cin >> a >> b >> w;
        }
    }
}
using namespace AdjacencyListDef;

void CreatePositive(){
    VNode G[N];
    int n, m; // 结点数、边数
    CreateAdjList(G, n, m);
    ANode *p;
    p = (ANode*)malloc(sizeof(ANode));
    cout << n << " " << m << endl;
    forn(i, 1, n){
        int cnt = 0;
        p = G[i].firstA;
        while(p){
            cnt ++;
            cout << i << " " << p->adjvex << " " << p->w << endl;
            p = p->next;
        }
        cout << i << "->OutDegree:" << cnt << endl; 
    }
}
void CreateReverse(){
    VNode RG[N];
    int n, m;
    CreateReverseAdjList(RG, n, m);
    ANode *p;
    p = (ANode*)malloc(sizeof(ANode));
    cout << n << " " << m << endl;
    forn(i, 1, n){
        int cnt = 0;
        p = RG[i].firstA;
        while(p){
            cnt ++;
            cout << i << " " << p->adjvex << " " << p->w << endl;
            p = p->next;
        }
        cout << i << "->InDegree:" << cnt << endl; 
    }
}

void solve(){
    CreatePositive();
    /*
    4 4
    1 3 4
    1 2 3
    1->OutDegree:2
    2 1 2
    2->OutDegree:1
    3 4 1
    3->OutDegree:1
    4->OutDegree:0
    */
    CreateReverse();
    /*
    4 4
    1 2 2
    1->InDegree:1
    2 1 3
    2->InDegree:1
    3 1 4
    3->InDegree:1
    4 3 1
    4->InDegree:1
    */
}

int main()
{
    IOS;
    solve();
    return 0;
}