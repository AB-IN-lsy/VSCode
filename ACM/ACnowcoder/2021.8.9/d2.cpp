/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-09 13:07:58
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-13 02:39:04
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

const int N = 1e5 + 16;
int b[N], c[N], d[N];
int n;

bool check(int k, int x){
    for(int i = 1; i < n; ++ i){
        int _or = (b[i] >> k) & 1;
        int _and = (d[i] >> k) & 1;
        if(_or && !_and) x ^= 1;
        if (_or && _and && !x) return 0;
        if (!_or && _and) return 0;
        if (!_or && !_and && x) return 0;
    }
    return 1;
}

int main()
{
    IOS;
    cin >> n;
    for(int i = 1; i < n; ++ i){
        cin >> b[i];
    }
    for(int i = 1; i < n; ++ i){
        cin >> c[i];
        d[i] = c[i] - b[i];
    }
    LL ans = 1;
    for(int i = 0; i < 32; ++ i){
        bool flag1 = check(i, 0),
             flag2 = check(i, 1);
        if(flag1 && flag2) ans *= 2;
        else if(flag1 || flag2) continue;
        else return cout << 0 << '\n', 0;
    }
    cout << ans << '\n';
    return 0;
}