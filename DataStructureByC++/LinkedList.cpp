/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-15 19:09:09
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-15 20:44:40
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

namespace LinkedListDef{
    typedef struct node{
        int data;
        struct node *next;
    }LNode, *LinkedList;

    LinkedList LinkedListInit(){
        LNode *L;
        L = (LNode*) malloc(sizeof(LNode));
        if(L == NULL){
            cout << "No space to be distributed" << endl;
            return NULL;
        }
        L -> next = NULL;
        return L;
    }

    int LinkedListLength(LinkedList L){
        // 头指针L表示链表名
        LNode *p;
        int j = 0;
        p = L -> next;
        while(p != NULL){
            j++;
            p = p -> next;
        }
        return j;
    }

    void LinkedListParameter(LinkedList L){
        // 头指针L表示链表名
        LNode *p;
        p = L -> next;
        while(p != NULL){
            cout << p -> data << " ";
            p = p -> next;
        }
    }

    LinkedList LinkedListLocate(LinkedList L, int x){
        //在单链表L中查找值为x的结点，找到后返回其指针，否则返回空
        LNode *p;
        p = L -> next;
        while(p != NULL && p -> data != x){
            p = p -> next;
        }
        if(!p){
            cout << "Not found" << endl;
            return NULL;
        }
        else return p;
    }

    void LinkedListInsert(LinkedList L, LNode *p, int x){
        //在结点p之前插入元素为x的结点
        LNode *pre, *s;
        pre = L;
        if(pre -> next != NULL && pre -> next != p){
            pre = pre -> next; //找p的前驱
        }
        if(!pre -> next){
            cout << "Not found *p" << endl;
            return;
        }
        // pre -> s -> p
        s = (LNode*)malloc(sizeof(LNode));
        s -> data = x;
        s -> next = pre -> next;
        pre -> next = p;
    }

    void LinkedListDel(LinkedList L, int i){
        //删除单链表L上的第i个结点
        LNode *pre;
        if(i < 1){
            cout << "Parameter fault" << endl;
            return;
        }
        pre = L -> next;
        int j = 0;
        while(pre != NULL && j < i - 1){
            j ++;
            pre = pre -> next;
        }
        if(pre == NULL){
            cout << "Position fault" << endl;
            return;
        }
        LNode *p;
        p = pre -> next;
        pre -> next = p -> next;
        free(p);
    }

    LinkedList LinkedListCreateHead(){
        LinkedList L, p; //声明L,p这个指针,其中L为头结点
        L = (LNode*)malloc(sizeof(LNode));
        L -> next = NULL;
        int x, flag = 999; //flag为终止符
        cin >> x;
        while(x != flag){
            p = (LNode*)malloc(sizeof(LNode));
            p -> data = x;
            p -> next = L -> next;
            L -> next = p;
            cin >> x;
        }
        return L;
    }

    LinkedList LinkedListCreateTail(){
        LinkedList L, r, p;
        L = (LNode*)malloc(sizeof(LNode));
        L -> next = NULL;
        r = L;
        int x, flag = 999; //flag为终止符
        cin >> x;
        while(x != flag){
            p = (LNode*)malloc(sizeof(LNode));
            p -> data = x;
            r -> next = p;
            r = p; //r变为新的尾结点
            cin >> x;
        }
        r -> next = NULL;
        return L;
    }
}
using namespace LinkedListDef;


void solve(){
    LinkedList L = LinkedListCreateTail();
    cout << LinkedListLength(L) << endl;
    LinkedListParameter(L);
    LinkedListDel(L, 1);
    cout << endl;
    LinkedListParameter(L);
    cout << endl;
    cout << LinkedListLocate(L, 3) -> data << " " << LinkedListLocate(L, 2)<< endl;
}

int main()
{
    IOS;
    solve();
    return 0;
}