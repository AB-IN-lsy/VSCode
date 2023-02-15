/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-21 21:12:21
 * @FilePath: \ACM\GPLT\L2-017.CPP
 * @LastEditTime: 2022-04-21 21:43:50
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
int n;
int a[N];

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (n & 1)
    {
        int step = n / 2;
        int sum_pre = accumulate(a + 1, a + 1 + step, 0);
        int sum_post = accumulate(a + 1 + step, a + n + 1, 0);
        int diff1 = sum_post - sum_pre;

        step = n / 2 + 1;
        sum_pre = accumulate(a + 1, a + 1 + step, 0);
        sum_post = accumulate(a + 1 + step, a + n + 1, 0);
        int diff2 = sum_post - sum_pre;

        int ans1 = diff1 >= diff2 ? n / 2 : n / 2 + 1;
        int ans2 = diff1 >= diff2 ? n / 2 + 1 : n / 2;

        printf("Outgoing #: %lld\n", ans2);
        printf("Introverted #: %lld\n", ans1);
        printf("Diff = %lld\n", max(diff1, diff2));
    }
    else
    {
        int sum_pre = accumulate(a + 1, a + 1 + n / 2, 0);
        int sum_post = accumulate(a + 1 + n / 2, a + n + 1, 0);
        printf("Outgoing #: %lld\n", n / 2);
        printf("Introverted #: %lld\n", n / 2);
        printf("Diff = %lld\n", sum_post - sum_pre);
    }
    return 0;
}