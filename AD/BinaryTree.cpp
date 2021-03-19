/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-19 19:05:31
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-19 20:21:31
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

namespace BinaryTreeDef{
    typedef struct Binode{
        char data;
        struct Binode *lc, *rc;
    }Binode, *BiTree;

    BiTree BinaryTreeCreate(){// 先序建树
        char x;
        cin >> x;
        BiTree T;
        if(x == '#'){
            T = NULL;
        }
        else{
            T = (Binode*)malloc(sizeof(Binode));
            T->data = x;
            T->lc = BinaryTreeCreate();
            T->rc = BinaryTreeCreate();
        }
        return T;
    }

    void PreOrderTraverse(BiTree T){
        if(T){
            cout << T->data << " ";
            PreOrderTraverse(T->lc);
            PreOrderTraverse(T->rc);
        }
    }
    void InOrderTraverse(BiTree T){
        if(T){
            InOrderTraverse(T->lc);
            cout << T->data << " ";
            InOrderTraverse(T->rc);
        }
    }
    void PostOrderTraverse(BiTree T){
        if(T){
            PostOrderTraverse(T->lc);
            PostOrderTraverse(T->rc);
            cout << T->data << " ";
        }
    }
    void LeafCount(BiTree T, int &num){
        if(T){
            LeafCount(T->lc, num);
            if(!T->lc && !T->rc) num ++;
            LeafCount(T->rc, num);
        }
    }
    void Exchange(BiTree T){
        BiTree S;
        if(T){
            S = T->lc;
            T->lc = T->rc;
            T->rc = S;
            Exchange(T->lc);
            Exchange(T->rc);
        }
    }
    int Depth(BiTree T){
        int d = 0;
        if(T){
            int L_d = Depth(T->lc);
            int R_d = Depth(T->rc);
            return L_d >= R_d ? L_d + 1 : R_d + 1;
        }
    }
}
using namespace BinaryTreeDef;

void solve(){
    BiTree T;
    // 1 2 4 # # # 3 # #
    T = BinaryTreeCreate();
    PreOrderTraverse(T);
    cout << endl;
    InOrderTraverse(T);
    cout << endl;
    PostOrderTraverse(T);
    cout << endl;
    int num;
    LeafCount(T, num);
    cout << num << endl;
    cout << Depth(T) << endl;
}

int main()
{
    IOS;
    solve();
    return 0;
}