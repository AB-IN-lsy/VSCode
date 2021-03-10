/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-10 10:49:08
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

const int N = 1E6 + 10;
int prime[N], flag[N];

void init(){
    mset(flag, 1);
    flag[1] = 0;
    int cnt = 0;
    for(int i = 2; i <= N; i ++){
        if(flag[i]){
            prime[++cnt] = i;
        }
        for(int j = 1; j <= cnt && (1ll) * prime[j] * i <= N; j++){
            flag[prime[j] * i] = 0;
            if(i % prime[j] == 0) break;
        }
    }
}

void solve(){
    init();
    forn(i, 1, 10) cout << prime[i] << " ";
}   

int main()
{
    IOS;
    solve();
    return 0;
}