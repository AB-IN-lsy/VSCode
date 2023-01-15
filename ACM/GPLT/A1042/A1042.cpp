/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-10 18:35:08
 * @FilePath: \GPLT\A1042\A1042.cpp
 * @LastEditTime: 2023-01-10 18:52:03
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

const int N = 55, INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    vector<string> ord(1);
    vector<char> v = {'S', 'H', 'C', 'D'};
    for (int i = 0; i < 4; ++i)
    {
        char pre = v[i];
        for (int j = 1; j <= 13; ++j)
        {
            string s = to_string(j);
            s = pre + s;
            ord.push_back(s);
        }
    }
    ord.push_back("J1");
    ord.push_back("J2");

    int k;
    cin >> k;
    vector<int> mp(N);
    for (int i = 1; i < N; ++i)
    {
        cin >> mp[i];
    }

    while (k--)
    {
        vector<string> new_ord(N);
        for (int i = 1; i < N; ++i)
        {
            new_ord[mp[i]] = ord[i];
        }
        ord = new_ord;
    }
    for (int i = 1; i < N; ++i)
    {
        cout << ord[i] << " "[i == N - 1];
    }
    return 0;
}