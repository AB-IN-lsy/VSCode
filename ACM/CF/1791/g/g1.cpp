#include <bits/stdc++.h>
using namespace std;
#define int long long

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int dp[N], v[N], V;

void solve()
{
    int n;
    cin >> n >> V;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        v[i] += i;
    }

    sort(v + 1, v + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (V >= v[i])
        {
            V -= v[i];
            ans++;
        }
        else
            break;
    }
    cout << ans << '\n';
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