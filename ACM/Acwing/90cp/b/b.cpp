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
    int m, s;
    cin >> m >> s;
    int s1 = s, s2 = s;
    vector<int> mn, mx;
    if (s > 9 * m || (!s && m > 1))
    {
        cout << "-1 -1\n";
        return 0;
    }
    // mx
    for (int i = 1; i <= m; ++i)
    {
        int t = min(9, s1);
        mx.push_back(t);
        s1 -= t;
    }
    // mn
    for (int i = 1; i < m; ++i)
    {
        int t = min(9, s2 - 1);
        mn.push_back(t);
        s2 -= t;
    }
    mn.push_back(s2);
    reverse(ALL(mn));

    for (auto i : mn)
        cout << i;
    cout << ' ';
    for (auto i : mx)
        cout << i;

    return 0;
}