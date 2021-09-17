/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-17 19:54:10
 * @FilePath: \Vscode\ACM\CF\2021.9.17\a.cpp
 * @LastEditTime: 2021-09-17 20:00:24
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

const int N = 1e3 + 10;
int a[N];
signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, greater<int>());
        int wid = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > wid)
            {
                wid++;
            }
        }
        cout << wid << '\n';
    }
    return 0;
}