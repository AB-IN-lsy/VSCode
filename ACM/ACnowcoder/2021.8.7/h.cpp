/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-11 09:17:21
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-11 09:46:30
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

const int N = 1e6 + 10;
int vis[N], n;
LL ans;
int main()
{
    IOS;    
    cin >> n;
    set <int, greater<int> > s;
    for(int i = 1; i <= n; ++ i){
        int x;
        cin >> x;
        vis[x] ++;
        s.insert(x); 
    }
    for(auto it : s){
        for(int i = 1; i * i <= it; ++ i){
            if(it % i == 0) ans += 1LL * vis[i] * vis[it / i] * vis[it];
            if(it % i == 0 && i != it / i) ans += 1LL * vis[i] * vis[it / i] * vis[it];
        }
    }
    cout << ans << '\n';
    return 0;
}