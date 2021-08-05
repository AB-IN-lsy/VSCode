/*
 * @Description: 1004
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-04 15:16:50
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-04 15:25:02
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1e5 + 10;
LL sum, a[N], m;
int t, n;

int main()
{
    IOS;
    cin >> t;
    while(t --){
        cin >> n >> m;
        sum = 0;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            sum += a[i];
        }
        LL cnt = 0, mx = a[1];
        bool flag = 0;
        for(int k = 1; k <= 2; k ++){
            for(int i = 1; i <= n; i ++){
                cnt += a[i];
                if(cnt < 0) cnt = 0;
                if(cnt >= m){
                    flag = 1;
                    cout << k << '\n';
                    break;
                }
                mx = max(cnt, mx);
            }
            if(flag) break;
        }
        if(flag) continue;

        if(sum <= 0) cout << "-1\n";
        else cout << 2 + (m - mx + sum - 1) / sum << '\n';
    }

    return 0;
}