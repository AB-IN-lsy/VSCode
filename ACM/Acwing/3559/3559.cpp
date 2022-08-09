/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-28 00:47:33
 * @FilePath: \Acwing\3559\3559.cpp
 * @LastEditTime: 2022-07-29 22:42:57
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> ne(n + 1);
    for(int i = 1; i < n; ++ i){
        ne[i] = i + 1;
    }
    ne[n] = 1;
    
    int p = n;
    for(int i = 1; i <= n; ++ i){
        p = ne[ne[p]]; // p = 2
        cout << ne[p] << ' '; // ne[p] = 3
        ne[p] = ne[ne[p]]; // ne[p] = 4
    }
    cout << '\n';
    return;
}


int main()
{
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}