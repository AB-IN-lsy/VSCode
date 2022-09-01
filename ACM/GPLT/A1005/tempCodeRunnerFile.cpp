/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-31 20:29:53
 * @FilePath: \GPLT\A1005\A1005.cpp
 * @LastEditTime: 2022-08-31 20:35:32
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

signed main()
{
    IOS;
    string s;
    cin >> s;
    int ans = 0;
    for (auto i : s)
    {
        ans += i - '0';
    }
    vector<string> mp = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    string res = to_string(ans);
    for (int i = 0; i < SZ(res); ++i)
    {
        cout << mp[res[i] - '0'] << " "[i == SZ(res) - 1];
    }

    return 0;
}