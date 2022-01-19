/*
 * @Author: NEFU AB-IN
 * @Date: 2022-01-15 13:21:18
 * @FilePath: \ACM\ACnowcoder\2022.1.15\h.cpp
 * @LastEditTime: 2022-01-15 13:22:21
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    unsigned LL n;
    cin >> n;
    if (n % 2)
        cout << n;
    else
        cout << -1;
    return 0;
}