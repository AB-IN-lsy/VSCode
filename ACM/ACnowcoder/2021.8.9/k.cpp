/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-09 16:20:42
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-13 02:39:00
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
#define PI                          acos(-1)
typedef pair<int , int>             PII;

int t;
double w, d, a, b;

int main()
{
    IOS;
    cin >> t;
    while(t --){
        cin >> w >> d;
        LL ans = 4;
        a = min(w, d);
        b = sqrt(w * w + d * d);
        for(int x = 0; x <= 100 && a * x <= PI; ++ x){
            ans = max(ans, (2 * x + 3 * (LL)((PI - x * a) / b) + 4));
        }
        for(int y = 0; y <= 100 && b * y <= PI; ++ y){
            ans = max(ans, (2 * (LL)((PI - y * b) / a) + 3 * y + 4));
        }
        cout << ans << '\n';
    }
    return 0;
}