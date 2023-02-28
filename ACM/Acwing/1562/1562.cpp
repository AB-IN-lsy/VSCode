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

vector<int> g[N];
int st[N];

signed main()
{
    IOS;
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
    }

    auto bfs = [&](int x) {
        queue<PII> q;
        q.push({x, 1});
        memset(st, 0, sizeof st);
        st[x] = 1;
        int ans = 0;
        while (SZ(q))
        {
            auto [u, cnt] = q.front();
            q.pop();
            if (cnt > l)
                return ans;
            for (auto v : g[u])
            {
                if (!st[v])
                {
                    ans++;
                    st[v] = 1;
                    q.push({v, cnt + 1});
                }
            }
        }
        return ans;
    };

    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        int x;
        cin >> x;
        cout << bfs(x) << '\n';
    }
    return 0;
}