/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-05 10:25:18
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-05 10:50:58
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 10;
int a[N], b[N], st[N];
int n, cnt, k;

int main()
{
    IOS;
    cin >> n >> k;
    for(int i = 1; i <= k; ++ i){
        int pos;
        cin >> pos >> a[pos];
    }
    for(int i = 1; i <= n; ++ i){
        if(a[i] && a[i] > a[i - 1] + 1){
            cout << "-1\n";
            return 0;
        }
        if(!a[i]) a[i] = a[i - 1] + 1;
    }

    int top = 0;
    for(int i = n; i >= 1; -- i){
        while(a[i] > top){
            st[++ top] = ++ cnt;
        }
        b[i] = st[top];
        top --;
    }
    for(int i = 1; i <= n; ++ i){
        cout << b[i] << " ";
    }
    return 0;
}
/*
7 3
1 1
2 2
3 1
*/
