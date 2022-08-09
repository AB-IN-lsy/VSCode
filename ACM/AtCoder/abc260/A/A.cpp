/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-17 19:59:16
 * @FilePath: \abc260\A\A.cpp
 * @LastEditTime: 2022-07-17 20:02:10
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    string s;
    cin >> s;

    map<char, int> st;
    for (auto i : s)
    {
        st[i]++;
    }
    int flag = 0;
    for (auto [a, b] : st)
    {
        if (b == 1)
        {
            flag = 1;
            cout << a << " ";
            return 0;
        }
    }
    if (!flag)
        cout << "-1\n";
    return 0;
}