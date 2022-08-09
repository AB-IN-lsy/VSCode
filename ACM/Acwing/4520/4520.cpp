/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-04 10:11:30
 * @FilePath: \Acwing\4520\4520.cpp
 * @LastEditTime: 2022-08-04 11:02:25
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e5 + 10;

int prime[N], st[N], cnt;

void solve()
{

    int n;
    cin >> n;

    vector<int> v = {1, 3, 7, 9};

    function<int(int, int)> dfs = [&](int n, int p) {
        int y, x;
        for (int i = 0; i < 4; ++i)
        {
            y = 10 * (p - 1) + v[i]; // 尾数
            string t = to_string(n) + to_string(y);
            x = stol(t);
            if (!st[x])
                return x;
        }
        return dfs(n, p + 1);
    };

    cout << dfs(n, 1) << '\n';

    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;

    function<void()> init = [&] {
        for (int i = 2; i < N; ++i)
        {
            if (!st[i])
            {
                prime[cnt++] = i;
            }
            for (int j = 0; prime[j] < N / i; ++j)
            {
                st[prime[j] * i] = 1;
                if (i % prime[j] == 0)
                    break;
            }
        }
    };
    init();
    while (T--)
        solve();
    return 0;
}