/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-01 14:24:23
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-01 15:45:37
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1E5 + 10;
LL a[N];

int main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int cnt = a[1] - k;
        LL ans = 0;
        for(int i = 1; i <= n; i ++){
            if(abs(cnt - a[i]) <= k){
                ans ++;
                cnt ++;
            }
            else if(a[i] - k > cnt){
                ans ++;
                cnt = a[i] - k + 1;
            }
        }
        cout << ans << endl;
    }   
    return 0;
}