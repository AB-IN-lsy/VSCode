/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-11 10:27:58
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.10\b.cpp
 * @LastEditTime: 2021-09-11 15:58:21
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
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
    int t;
    cin >> t;
    while (t--)
    {
        string m, c;
        int k;
        cin >> m >> c >> k;
        if (m == c)
        {
            cout << "YES" << '\n';
            continue;
        }

        string hou = c.substr(SZ(c) - k, SZ(c));
        c = c.substr(0, SZ(c) - k);
        int flag = 0;
        string c_tmp = c;
        for (int i = 0; c[i]; ++i)
        {
            c_tmp.insert(i, hou);
            if (c_tmp == m)
            {
                cout << "YES" << '\n';
                flag = 1;
                break;
            }
            c_tmp = c;
        }
        if (!flag)
            cout << "NO" << '\n';
    }
    return 0;
}