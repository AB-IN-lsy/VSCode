/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-09 13:07:58
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-09 22:02:01
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
int a[N], b[N], c[N], d[N];
int n;
int main()
{
    IOS;
    cin >> n;
    for(int i = 2; i <= n; i ++){
        cin >> b[i];
    }
    for(int i = 2; i <= n; i ++){
        cin >> c[i];
        d[i] = c[i] - b[i];
    }
    LL ans = 1;
    for(int i = 0; i <= 31; i ++){
        for(int j = 1; j <= n; j ++) a[j] = -1;
        for(int j = 2; j <= n; j ++){
            int b_bin = (b[j] >> i) & 1;
            int d_bin = (d[j] >> i) & 1;
            if(b_bin == 0){
                if(a[j - 1] == 1 || a[j] == 1) ans = 0;
                a[j - 1] = 0;
                a[j] = 0;
            }
            if(d_bin == 1){
                if(a[j - 1] == 0 || a[j] == 0) ans = 0;
                a[j - 1] = 1;
                a[j] = 1;
            }
        }
        LL cnt = 0;
        for(int j = 1; j <= n; j ++){
            if(a[j] != -1) cnt ++;
        }
        if(!cnt) {
            ans *= 2;
        }
        
    }
    cout << ans << '\n';
    return 0;
}