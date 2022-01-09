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

const int N = 2e5 + 10;
int a[N], if_exist[N], cnt[N], if_exist_cnt[N], cnt_cnt[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if_exist[a[i]] = 1;
        cnt[a[i]]++;
    }
    for (int i = 0; i <= n; ++i)
    {
        if_exist_cnt[i] = if_exist[i] + if_exist_cnt[i - 1];
        cnt_cnt[i] = cnt[i] + cnt_cnt[i - 1];
    }
    int flag = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (flag == 1)
        {
            cout << "-1 ";
            continue;
        }
        if (i == 0)
        {
            cout << cnt[i] << " ";
            continue;
        }
        else if (i == 1)
        {
            if (if_exist[0])
            {
                cout << cnt[1] << " ";
            }
            else
            {
                flag = 1;
                cout << "-1 ";
            }
        }
        else
        {
            int empty = (i - 1) - (if_exist_cnt[i - 1] - if_exist_cnt[0]);
            // 0~i-1 空的数量
            int free = cnt_cnt[i - 2] - cnt_cnt[-1] - (i - 1);
            if (free < empty)
            {
                flag = 1;
                cout << "-1 ";
            }
            else
            {
                
            }
        }
    }
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}