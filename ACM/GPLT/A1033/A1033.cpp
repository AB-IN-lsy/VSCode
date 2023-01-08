#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 510, INF = 0x3f3f3f3f;

int c_max, d, d_avg, n;
struct sa
{
    double p, d;

    bool operator<(const sa &t) const
    {
        return d < t.d;
    }
};

signed main()
{
    IOS;
    cin >> c_max >> d >> d_avg >> n;
    vector<sa> s;
    for (int i = 0; i < n; i++)
    {
        double p, d;
        cin >> p >> d;
        s.push_back({p, d});
    }
    s.push_back({0, (double)d}); // 加入终点，终点是距离为d，花费为0的加油站

    sort(s.begin(), s.end());

    if (s[0].d)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    double res = 0, oil = 0; // res为花费，oil为当前油含量
    for (int i = 0; i < n;)
    {
        int k = -1; // 找最近的加油站

        for (int j = i + 1; j <= n && s[j].d - s[i].d <= c_max * d_avg; ++j)
        {
            if (s[j].p < s[i].p)
            { // 找最近的且比当下便宜的加油站
                k = j;
                break;
            }
            else if (k == -1 || s[j].p < s[k].p)
                k = j; // 找相对小的
        }
        if (k == -1)
        {
            printf("The maximum travel distance = %.2lf\n",
                   s[i].d + (double)c_max * d_avg); // 如果走不到终点，则最远距离为目前的距离加上剩下油跑的距离
            return 0;
        }

        if (s[k].p <= s[i].p) // 第一种情况，直接去最近的便宜处加油
        {
            res += ((s[k].d - s[i].d) / d_avg - oil) * s[i].p;
            i = k;
            oil = 0;
        }
        else
        {
            res += (c_max - oil) * s[i].p;
            oil = c_max - (s[k].d - s[i].d) / d_avg;
            i = k;
        }
    }
    printf("%.2lf\n", res);

    return 0;
}