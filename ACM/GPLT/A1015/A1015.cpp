/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-03 21:36:20
 * @FilePath: \GPLT\A1015\A1015.cpp
 * @LastEditTime: 2022-09-03 23:26:52
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;
const int N = 100100;

int st[N], prime[N], cnt;

void init()
{
    st[0] = st[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (!st[i])
        {
            prime[cnt++] = i;
        }
        for (int j = 0; prime[j] < N / i; ++j)
        {
            st[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

signed main()
{
    IOS;
    init();
    int n, d;
    while (cin >> n, n > 0)
    {
        cin >> d;
        int ans = 0;

        // 转d进制
        string s;
        int tmp = n;
        while (tmp)
        {
            s.push_back(tmp % d + '0');
            tmp /= d;
        }

        // 转10进制
        for (auto i : s)
            ans = ans * d + i - '0';

        if (!st[n] && !st[ans])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}