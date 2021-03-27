/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-25 23:12:45
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

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 1;
    s[s.find('*')] = 'x';
    for(int i = 0; i < n; i++){
        if(s[i] == 'x'){
            for(int j = i + k; j >= i + 1; j--){
                if(j > n - 1) j = n - 1;
                if(s[j] == '*'){
                    cnt ++;
                    s[j] = 'x';
                    i = j - 1;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}