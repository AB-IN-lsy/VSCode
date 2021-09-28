/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-28 22:30:17
 * @FilePath: \ACM\CF\2021.9.28.div3\a.cpp
 * @LastEditTime: 2021-09-28 22:38:06
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

const int N = 1e4 + 10;

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        for (auto i : s)
        {
            if (i == 'A')
                a++;
            if (i == 'B')
                b++;
            if (i == 'C')
                c++;
        }
        if (b == a + c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}