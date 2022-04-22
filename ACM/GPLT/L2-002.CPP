/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-19 16:37:06
 * @FilePath: \ACM\GPLT\L2-002.CPP
 * @LastEditTime: 2022-04-20 20:17:37
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e5 + 10;
int h, e[N], ne[N], st[N];

int n;
signed main()
{
    IOS;
    cin >> h >> n;
    for (int i = 1; i <= n; ++i)
    {
        int address, val, next;
        cin >> address >> val >> next;
        e[address] = val;
        ne[address] = next;
    }

    vector<int> v1, v2;
    for (int i = h; ~i; i = ne[i])
    {
        int val = e[i];
        if (st[abs(val)])
            v2.push_back(i);
        else
        {
            st[abs(val)] = 1;
            v1.push_back(i);
        }
    }
    for (int i = 0; i < SZ(v1); ++i)
    {
        printf("%05lld %lld ", v1[i], e[v1[i]]);
        if (i == SZ(v1) - 1)
            printf("-1\n");
        else
            printf("%lld\n", v1[i + 1]);
    }
    for (int i = 0; i < SZ(v2); ++i)
    {
        printf("%05lld %lld ", v2[i], e[v2[i]]);
        if (i == SZ(v2) - 1)
            printf("-1\n");
        else
            printf("%lld\n", v2[i + 1]);
    }
    return 0;
}