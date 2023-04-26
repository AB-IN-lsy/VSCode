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

const int N = 550, INF = 0x3f3f3f3f;

int n;
int dist[N][N], d[N];
char a[N];

signed main()
{
    memset(dist, INF, sizeof dist);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        getchar();
        char sex;
        scanf("%c", &sex);
        a[i] = sex;
        int k, v, w;
        scanf("%d", &k);
        while (k--)
        {
            scanf("%d:%d", &v, &w);
            dist[i][v] = w;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                dist[i][i] = 0;
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] != a[j])
                d[i] = max(d[i], dist[j][i]);

    vector<int> ansm, ansf;
    int mnm = INF, mnf = INF;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 'M')
            mnm = min(mnm, d[i]);
        else
            mnf = min(mnf, d[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 'M')
            continue;
        if (d[i] == mnf)
            ansf.push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 'F')
            continue;
        if (d[i] == mnm)
            ansm.push_back(i);
    }

    printf("%d", ansf[0]);
    for (int i = 1; i < SZ(ansf); ++i)
    {
        printf(" %d", ansf[i]);
    }
    printf("\n%d", ansm[0]);
    for (int i = 1; i < SZ(ansm); ++i)
    {
        printf(" %d", ansm[i]);
    }
    return 0;
}