#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 100;
char a[N][N];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= m; ++i)
    {
        a[n + 1][i] = 'o';
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '*')
            {
                for (int k = i + 1; k <= n + 1; ++k)
                {
                    if (a[k][j] == 'o' || a[k][j] == '*')
                        break;
                    a[k - 1][j] = '.';
                    a[k][j] = '*';
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%s\n", a[i] + 1);
    }
    printf("\n");
}

signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}