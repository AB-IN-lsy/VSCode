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

const int N = 5e5 + 10, INF = 0x3f3f3f3f;

#define lowbit(x) ((x) & -(x))

int a[N], tree[N], n, k, dp[N];
void add(int x, int d)
{
    while (x <= n)
    {
        tree[x] = max(tree[x], d);
        x += lowbit(x);
    }
}
int query(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum = max(sum, tree[x]);
        x -= lowbit(x);
    }
    return sum;
}

signed main()
{
    IOS;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i - k > 1)
        {
            dp[i] = query(i - k - 1) + a[i];
        }
        else
            dp[i] = a[i];
        add(i, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}