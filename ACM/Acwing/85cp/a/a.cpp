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

int n, cnt11, cnt12, cnt21, cnt22;

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
            cnt11 += x, cnt12 += y;
        else
            cnt21 += x, cnt22 += y;
    }
    if (cnt11 >= cnt12)
        cout << "LIVE\n";
    else
        cout << "DEAD\n";

    if (cnt21 >= cnt22)
        cout << "LIVE\n";
    else
        cout << "DEAD\n";
    return 0;
}