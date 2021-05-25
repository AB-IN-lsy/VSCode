/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-17 18:20:26
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-17 19:33:30
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

namespace SequenceStackDef{
    const int N = 1e4 + 10;
    typedef struct{
        int data[N];
        int top;
    }SeqStack;

    SeqStack SeqStackInit(){
        SeqStack S;
        S.top = 0;
        return S;
    }

    SeqStack SeqStackPush(SeqStack S, int x){
        if(S.top == N){
            cout << "Full" << endl;
            return S;
        }
        S.data[++S.top] = x;
        return S;
    }
    
    SeqStack SeqStackPop(SeqStack S, int &x /* int *x */){
        if(S.top == 0){
            cout << "Empty" << endl;
            return S;
        }
        x = S.data[S.top--];
        // *x = S.data[S.top--];
        return S;
    }
}
using namespace SequenceStackDef;

namespace LinkedStackDef{
    typedef struct StackNode{
        int data;
        struct StackNode *next;
    }SNode, *LinkedStack; 

    LinkedStack LinkedStackInit(){
        LinkedStack top;
        top = NULL;
        return top;
    }

    bool LinkedStackEmpty(LinkedStack top){
        if(top == NULL) return false;
        else return true;
    }

    LinkedStack LinkedStackPush(LinkedStack top, int x){
        SNode *p;
        p = (SNode*)malloc(sizeof(SNode));
        p -> data = x;
        p -> next = top;
        top = p;
        return top;
    }

    LinkedStack LinkedStackPop(LinkedStack top, int &x){
        SNode *p;
        p = (SNode*)malloc(sizeof(SNode));
        if(top != NULL){
            x = top -> data;
            p = top;
            top = top -> next;
            free(p);
        }
        else{
            cout << "Empty" << endl;
        }
        return top;
    }
}
using namespace LinkedStackDef;



void solve(){
    // SequenceStack
    int n, x;
    cin >> n;
    SeqStack S = SeqStackInit();
    forn(i, 1, n) cin >> x, S = SeqStackPush(S, x);
    forn(i, 1, n) {
        S = SeqStackPop(S, x);
        // S = SeqStackPop(S, &x);
        // 都可以通过函数修改主函数x的值
        cout << x << " ";
    }
    cout << endl;
    /*******************************************************/
    // LinkedStack
    cin >> n;
    LinkedStack top = LinkedStackInit();
    forn(i, 1, n) cin >> x, top = LinkedStackPush(top, x);
    forn(i, 1, n) {
        top = LinkedStackPop(top, x);
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    IOS;
    solve();
    return 0;
}