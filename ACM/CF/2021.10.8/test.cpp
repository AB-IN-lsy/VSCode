/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-08 21:39:22
 * @FilePath: \ACM\CF\2021.10.8\test.cpp
 * @LastEditTime: 2021-10-08 21:39:23
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
    int a[10] = {0};
    a[1]++;
    a[3]--;
    for (int i = 1; i <= 10; ++i)
    {
        a[i] += a[i - 1];
    }
    return 0;
}