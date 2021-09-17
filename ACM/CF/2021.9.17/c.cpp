/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-17 21:01:28
 * @FilePath: \Vscode\ACM\CF\2021.9.17\c.cpp
 * @LastEditTime: 2021-09-17 21:23:12
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

signed main()
{
    IOS;
    LL a;
    cin >> a;
    LL cnt = 0x3f3f3f3f, flag = 0;
    for (LL j = 2; j <= a / j; j++)
    {
        while (a % j == 0)
        {
            a /= j;
            if (!flag)
            {
                cnt = j;
                flag = 1;
            }
            else
            {
                if (cnt != j)
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    if (flag && a > 1 && a != cnt)
        cout << 1;
    else
        cnt == 0x3f3f3f3f ? cout << a : cout << cnt;
    return 0;
}