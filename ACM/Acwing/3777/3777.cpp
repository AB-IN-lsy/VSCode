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

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int b = 0, w = 0;
    vector<int> bb, ww;
    for (int i = 0; i < SZ(s); ++i)
        if (s[i] == 'B')
            b++, bb.push_back(i + 1);
        else
            w++, ww.push_back(i + 1);
    if ((b & 1) && (w & 1))
    {
        cout << "-1\n";
        return;
    }
    auto f = [&](vector<int> &v) {
        vector<int> ans;
        for (int i = 0; i < SZ(v); i += 2)
        {
            int x = v[i], y = v[i + 1];
            for (int j = x; j < y; ++j)
                ans.push_back(j);
        }
        cout << SZ(ans) << '\n';
        for (auto i : ans)
            cout << i << ' ';
        if (SZ(ans))
            cout << '\n';
    };
    if (!(b & 1))
        f(bb);
    else
        f(ww);
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}