#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int n, q;

signed main()
{
    IOS;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> g[N];

    auto get = [&](int id, int x) {
        for (int i = 1; i <= x / i; ++i)
        {
            if (x % i == 0)
            {
                g[i].push_back(id);
                if (i != x / i)
                    g[x / i].push_back(id);
            }
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        get(i, a[i]);
    }

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        cout << upper_bound(ALL(g[x]), r) - lower_bound(ALL(g[x]), l) << '\n';
    }

    return 0;
}