/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-17 18:10:39
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-17 22:26:48
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

const int N = 1e4 + 10;
namespace SequenceQueueDef{
    typedef struct{
        int data[N];
        int front, rear;
    }SeQueue;

    SeQueue SeQueueInit(){
        SeQueue Q;
        Q.front = 0;
        Q.rear = 0;
        return Q;
    }

    int SeQueueFront(SeQueue Q){
        return Q.data[Q.front];
    }

    bool SeQueueEmpty(SeQueue Q){
        return Q.front == Q.rear;
    }

    SeQueue SeQueuePush(SeQueue Q, int x){
        if( (Q.rear + 1) % N == Q.front){
            cout << "Full" << endl;
            return Q;
        }
        Q.data[Q.rear] = x;
        Q.rear = (Q.rear + 1) % N;
        return Q;
    }

    SeQueue SeQueuePop(SeQueue Q, int &x){
        if(SeQueueEmpty(Q)){
            cout << "Empty" << endl;
            return Q;
        }
        x = Q.data[Q.front];
        Q.front = (Q.front + 1) % N;
        return Q;
    }
}
using namespace SequenceQueueDef;

namespace LinkedQueueDef{
    typedef struct QueueNode{
        int data;
        struct QueueNode *next;
    }QNode, *QueuePtr;

    typedef struct Queue{
        QueuePtr front;
        QueuePtr rear;
    }*LinkedQueue; // 需要两个单链表，即定义两个头指针

    LinkedQueue LinkedQueueInit(){
        LinkedQueue Q;
        Q -> front = Q -> rear = (QNode*)malloc(sizeof(QNode)); // 让f和r都各指向一个不存数值的结点
        Q -> front -> next = NULL;
        /*
        QNode *p;
        p = (QNode*)malloc(sizeof(QNode));
        Q -> front = Q -> rear = p; 这么写不行，指向了同一空间，会有参数错误
        */
        return Q;
    }

    bool LinkedQueueEmpty(LinkedQueue Q){
        return Q -> front == Q -> rear;
    }

    LinkedQueue LinkedQueuePush(LinkedQueue Q, int x){
        QNode *p;
        p = (QNode*)malloc(sizeof(QNode));
        p -> data = x;
        p -> next = NULL;
        Q -> rear -> next = p;
        Q -> rear = p;
        return Q;
    }

    LinkedQueue LinkedQueuePop(LinkedQueue Q, int &x){
        if(LinkedQueueEmpty(Q)){
            cout << "Empty" << endl;
            return Q;
        }
        QNode *p;
        p = (QNode*)malloc(sizeof(QNode));
        p = Q -> front -> next; // 需弹出的结点
        Q -> front -> next = p -> next;
        x = p -> data;
        if(p == Q -> rear) Q -> rear = Q -> front; //为空
        free(p);
        return Q;
    }
}
using namespace LinkedQueueDef;

void solve(){
    //SequenceQueue
    SeQueue Q = SeQueueInit();
    int n, x;
    cin >> n;
    forn(i, 1, n) cin >> x, Q = SeQueuePush(Q, x);
    forn(i, 1, n) Q = SeQueuePop(Q, x), cout << x << " ";
    cout << endl;

    //LinkedQueue
    LinkedQueue Q1 = LinkedQueueInit();
    cin >> n;
    forn(i, 1, n) cin >> x, Q1 = LinkedQueuePush(Q1, x);
    forn(i, 1, n) Q1 = LinkedQueuePop(Q1, x), cout << x << " ";
    cout << endl;
}

int main()
{
    IOS;
    solve();
    return 0;
}