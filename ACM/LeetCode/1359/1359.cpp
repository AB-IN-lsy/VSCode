#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define SZ(X) ((int)(X).size())
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

// #undef int;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int countOrders(int n)
    {
        vector<int> f(N);
        const int P = 1e9 + 7;
        f[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            f[i] = f[i - 1] * (2 * i - 1) * i % P;
        }
        return f[n];
    }
};

// ---------------------

signed main()
{
    Solution solution;
    return 0;
}