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
    cin >> n;
    string s;
    cin >> s;

    s = '0' + s;
    unordered_map<char, int> st;
    vector<int> a(n + 10), b(n + 10);
    for (int i = 1; i < SZ(s); ++i)
    {
        if (!st.count(s[i]))
            a[i]++;
        st[s[i]]++;
    }
    for (int i = 1; i < SZ(s); ++i)
    {
        a[i] += a[i - 1];
    }
    st.clear();
    for (int i = SZ(s) - 1; i >= 1; --i)
    {
        if (!st.count(s[i]))
            b[i]++;
        st[s[i]]++;
    }
    for (int i = SZ(s) - 1; i >= 1; --i)
    {
        b[i] += b[i + 1];
    }

    int mx = 0;
    for (int i = 1; i + 1 < SZ(s); ++i)
    {
        int ans = a[i] + b[i + 1];
        mx = max(ans, mx);
    }
    cout << mx << '\n';

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