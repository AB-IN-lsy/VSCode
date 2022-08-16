/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-11 09:28:03
 * @FilePath: \Acwing\3381\3381.cpp
 * @LastEditTime: 2022-08-11 09:43:04
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    unordered_map<char, int> ctoi;
    unordered_map<int, char> itoc;
    char i = 'a';
    int cnt = 1;
    while (cnt <= 9)
    {
        itoc[cnt] = i;
        int n = (i == 'p' || i == 'w') ? 4 : 3;
        for (int j = 1; j <= n; ++j)
        {
            ctoi[i] = cnt;
            i++;
        }
        cnt++;
    }

    string s;
    while (cin >> s)
    {
        int res = 0;
        for (int i = 0; i < SZ(s); ++i)
        {
            if (i && ctoi[s[i]] == ctoi[s[i - 1]])
            {
                res += 2;
            }
            res += (s[i] - itoc[ctoi[s[i]]] + 1);
        }
        cout << res << '\n';
    }
    return 0;
}