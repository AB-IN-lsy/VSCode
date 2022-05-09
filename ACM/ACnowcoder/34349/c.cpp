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

const int N = 1e6 + 10, M = 1e3 + 10;

signed main()
{
    IOS;
    bitset<N> dp;
    dp.set(0);

    for (int i = 1; i <= 5; ++i)
    {
        bitset<N> tmp;
        for (int j = 1; j < M; ++j)
        {
            tmp |= dp << (j * j);
        }
        dp = tmp;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp.test(n) ? "YES" : "NO") << '\n';
    }
    return 0;
}