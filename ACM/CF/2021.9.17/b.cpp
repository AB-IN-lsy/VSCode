/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-17 20:01:07
 * @FilePath: \Vscode\ACM\CF\2021.9.17\b.cpp
 * @LastEditTime: 2021-09-17 20:24:00
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

int a, b, c;
char ans[110];

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        memset(ans, 0, sizeof ans);
        int n;
        cin >> n;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int cnt = 0, sum = 0;
        for (auto &i : s)
        {
            if (i == 'R' && b)
            {
                b--;
                ans[cnt] = 'P';
                sum++;
            }
            if (i == 'P' && c)
            {
                c--;
                ans[cnt] = 'S';
                sum++;
            }
            if (i == 'S' && a)
            {
                a--;
                ans[cnt] = 'R';
                sum++;
            }
            cnt++;
        }
        if (sum >= (n + 1) / 2)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
            continue;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!ans[i] && a)
            {
                a--;
                ans[i] = 'R';
            }
            else if (!ans[i] && b)
            {
                b--;
                ans[i] = 'P';
            }
            else if (!ans[i] && c)
            {
                c--;
                ans[i] = 'S';
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}