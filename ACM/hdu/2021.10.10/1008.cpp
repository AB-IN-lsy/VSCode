/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-10 12:09:01
 * @FilePath: \ACM\Hdu\2021.10.10\1008.cpp
 * @LastEditTime: 2021-10-10 14:57:29
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
    int ans = 0;
    int a[5] = {0, 1, 2, 3, 4};
    do
    {
        for (int i = 1; i <= 4; ++i)
        {
            cout << a[i];
        }
        ans++;
    } while (next_permutation(a + 1, a + 1 + 4));

    return 0;
}