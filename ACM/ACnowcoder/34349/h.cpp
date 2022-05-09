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

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    vector<int> deg(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    int cnt = count(deg.begin() + 1, deg.end(), 1);

    printf("%.6lf", 2.0 * k / cnt);
    return 0;
}