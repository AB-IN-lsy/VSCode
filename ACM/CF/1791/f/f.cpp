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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int f(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
int a[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (f(a[i]) != a[i])
            st.insert(i);
    }
    st.insert(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            int val = l;
            while (1)
            {
                auto t1 = st.lower_bound(val);
                int pos = *t1;
                if (pos > r)
                    break;
                a[pos] = f(a[pos]);
                if (f(a[pos]) == a[pos])
                    st.erase(pos);
                val = pos + 1;
            }
        }
        else
        {
            int pos;
            cin >> pos;
            cout << a[pos] << '\n';
        }
    }
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