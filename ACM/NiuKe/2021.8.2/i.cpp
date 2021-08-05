/*
 * @Description: i
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-02 13:16:58
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-02 13:47:20
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

struct sa
{
    int l, r;
};

bool cmp(const sa a, const sa b){
    if(a.l != b.l) return a.l < b.l;
    else return a.r < b.r;
}

const int N = 1010;
sa a[N];
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; i ++){
            int l, r;
            cin >> l >> r;
            a[i] = sa{l, r};
        }
        sort(a + 1, a + 1 + m, cmp);
        if(m == 1){
            cout << 1 << endl;
            cout << a[1].l << " " << a[1].r << endl;
        }
        else{
            cout << m << endl;
            for(int i = 1; i <= m - 1; i ++){
                cout << a[i + 1].l << " " << a[i].r << endl;
            }
            cout << a[1].l << " " << a[m].r << endl;
        }
    }

    return 0;
}