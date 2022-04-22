/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 20:47:30
 * @FilePath: \ACM\GPLT\L2-009.CPP
 * @LastEditTime: 2022-04-20 20:56:41
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

const int N = 1e4 + 10;
int n;
int cnt[N];
double sum[N];

struct sa
{
    int id, cnt;
    double sum;
};

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int k;
        double sum1 = 0.0;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            int v;
            double p;
            cin >> v >> p;
            cnt[v] += 1;
            sum[v] += p;
            sum1 += p;
        }
        sum[i] -= sum1;
    }
    vector<sa> v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back({i, cnt[i], sum[i]});
    }

    sort(v.begin(), v.end(), [&](sa a, sa b) {
        if (a.sum != b.sum)
            return a.sum > b.sum;
        else if (a.cnt != b.cnt)
            return a.cnt > b.cnt;
        return a.id < b.id;
    });

    for (auto [id, cnt_, sum_] : v)
    {
        printf("%lld %.2lf\n", id, sum_ / 100.0);
    }
    return 0;
}