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

int n, sum;
int a[N], b[N];
int tot, cnt1, cnt2;
signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        b[i] = b[i - 1] + a[i];
    }
    if (n < 3 || sum % 3)
    {
        cout << "0\n";
        return 0;
    }
    int avg = sum / 3;
    for (int i = 1; i < n; ++i)
    {
        // 针对每一个位置进行判断
        if (b[i] == avg) // 第一部分
            cnt1++;
        if (b[n] - b[i + 1]) // 第二刀，分开二三数组，所以第二刀最小只能在i+2，因为必须留出一个给第二组
            cnt2 += cnt1;
    }
    cout << cnt2 << '\n';
    return 0;
}