/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-14 18:59:40
 * @FilePath: \Acwing\86cp\a.cpp
 * @LastEditTime: 2023-01-14 19:04:37
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

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> kind(3);
    vector<string> s = {"chest", "biceps", "back"};
    int mx = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        kind[i % 3] += x;
        if (kind[i % 3] > mx)
        {
            mx = kind[i % 3];
            ans = i % 3;
        }
    }
    cout << s[ans];
    return 0;
}