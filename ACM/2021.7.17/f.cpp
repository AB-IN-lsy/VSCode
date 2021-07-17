/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-17 12:54:03
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-17 13:29:41
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

int a[] = {
    3,6,9,
    10,12,13,15,16,18,19,
    20,21,23,24,26,27,29,
    30,31,32,33,34,35,36,37,38,39,
    40,42,43,45,46,48,49,
    50,51,53,54,56,57,59,
    60,61,62,63,64,65,66,67,68,69,
    70,72,73,75,76,78,79,
    80,81,83,84,86,87,89,
    90,91,92,93,94,95,96,97,98,99
};
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        LL ans = 0;
        LL l, r;
        cin >> l >> r;
        if(l >= 100){
            cout << r - l + 1 << endl;
            continue;
        }
        if(r >= 100){
            ans += (r - 99);
            r = 99;
        }
        ans += (upper_bound(a, a + 75, r) - a) - (lower_bound(a, a + 75, l) - a);
        cout << ans << endl;
    }
    return 0;
}
/*
6
4 10
5 16
1 20
1 100
120 130
100000 1000000

3
6
11
76
11
900001
*/