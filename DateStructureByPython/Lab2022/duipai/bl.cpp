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

bool judge(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i < n; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

signed main()
{
    IOS;
    cin >> n;
    cout << judge(n);
    return 0;
}