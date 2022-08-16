/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-16 09:32:29
 * @FilePath: \Acwing\692\692.cpp
 * @LastEditTime: 2022-08-16 09:39:21
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

const int N = 5010;

signed main()
{
    IOS;
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_)
    {
        int n;
        cin >> n;
        vector<int> b(5010);
        for (int i = 1; i <= n; ++i)
        {
            int l, r;
            cin >> l >> r;
            b[l]++;
            b[r + 1]--;
        }
        for (int i = 1; i < N; ++i)
        {
            b[i] += b[i - 1];
        }
        int p;
        cin >> p;
        printf("Case #%lld:", _);
        while (p--)
        {
            int x;
            cin >> x;
            printf("% lld", b[x]);
        }
        printf("\n");
    }
    return 0;
}