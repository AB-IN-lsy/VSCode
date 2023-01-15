/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-09 13:35:57
 * @FilePath: \GPLT\A1039\A1039.cpp
 * @LastEditTime: 2023-01-09 13:42:09
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n, k;
unordered_map<string, vector<int>> g;

signed main()
{
    IOS;
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        int idx, m;
        cin >> idx >> m;
        for (int j = 0; j < m; ++j)
        {
            string s;
            cin >> s;
            g[s].push_back(idx);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        cout << s << " " << SZ(g[s]);
        sort(ALL(g[s]));
        for (int j = 0; j < SZ(g[s]); ++j)
        {
            cout << " " << g[s][j];
        }
        cout << '\n';
    }
    return 0;
}