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
const int N = 1e6 + 10;
int n;

signed main()
{
    IOS;
    srand(time(0));
    int n = rand() % 10000 + 1, m = rand() % 10000 + 1;
    cout << n << " " << m << '\n';
    for (int i = 1; i <= n; ++i)
    {
        cout << rand() % 2000000000 - 1000000000 << " "[i == n];
    }
    cout << '\n';
    for (int i = 1; i <= m; ++i)
    {
        cout << rand() % 2000000000 - 100000000 << " "[i == m];
    }
    return 0;
}
