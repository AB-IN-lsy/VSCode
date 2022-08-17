/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 16:04:17
 * @FilePath: \Acwing\3526\3526.cpp
 * @LastEditTime: 2022-08-17 16:17:49
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

const int N = 10010;

signed main()
{
    IOS;
    int n, cnt = 0;
    vector<int> st(N), prime(N);
    auto init = [&] {
        for (int i = 2; i < N; ++i)
        {
            if (!st[i])
            {
                prime[cnt++] = i;
            }
            for (int j = 0; i < N / prime[j]; ++j)
            {
                st[i * prime[j]] = 1;
                if (i % prime[j] == 0)
                    break;
            }
        }
    };

    init();
    while (cin >> n)
    {
        int flag = 0;
        for (int i = 2; i < n; ++i)
        {
            if (!st[i] && i % 10 == 1)
            {
                cout << i << " ";
                flag = 1;
            }
        }
        if (!flag)
            cout << "-1";
        cout << '\n';
    }
    return 0;
}