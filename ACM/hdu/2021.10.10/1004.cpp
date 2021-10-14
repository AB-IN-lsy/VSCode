/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-13 18:43:18
 * @FilePath: \ACM\Hdu\2021.10.10\1004.cpp
 * @LastEditTime: 2021-10-13 18:43:18
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
int t;
LL x;
int main()
{
    IOS;
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (x == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}