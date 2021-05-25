#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m , k, x;
    cin >> n >> m >> k;
    while(k --){
        stack <int> s;
        int ans = 1;
        for(int i = 1; i <= n; i++){
            cin >> x;
            if(x != ans) {
                s.push(x);
                if(s.size() > m){
                    break;
                }
            }
            else{
                ans ++;
                while(!s.empty()){
                    if(s.top() == ans) s.pop(), ans ++;
                    else break;
                }
            }
        }
        if(s.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
