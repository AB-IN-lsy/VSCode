/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-16 18:12:57
 * @FilePath: \Acwing\3768\3768.cpp
 * @LastEditTime: 2023-02-16 19:00:12
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
    int n, ans = 0;
    string s;

    cin >> n >> s;
    for (int i = 0, j = 0; i < n; ++ i)
    {
        if(s[i] != 'x') continue;
        j = i;
        while (s[j] == 'x' && j < n)
            j++;
        ans += max(0, j - i - 2);
        i = j - 1;
    }
    cout << ans;
    return 0;
}