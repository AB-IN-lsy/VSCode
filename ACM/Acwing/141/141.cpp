/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-24 12:23:39
 * @FilePath: \Acwing\141\141.cpp
 * @LastEditTime: 2023-02-26 09:53:59
 */
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

const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int ne[N];

signed main()
{
    int T = 1;
    int n;
    string s;
    while (cin >> n, n)
    {
        cin >> s;
        s = " " + s;
        for (int i = 2, j = 0; i <= n; ++i)
        {
            while (j && s[i] != s[j + 1])
                j = ne[j];
            if (s[i] == s[j + 1])
                ++j;
            ne[i] = j;
        }
        printf("Test case #%d\n", T++);
        for (int i = 1; i <= n; ++i)
        {
            int t = i - ne[i];
            if (i % t == 0 && i / t > 1)
            {
                cout << i << " " << i / t << '\n';
            }
        }
        printf("\n");
    }
    return 0;
}