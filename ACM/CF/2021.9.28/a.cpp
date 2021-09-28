/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-28 19:43:04
 * @FilePath: \ACM\CF\2021.9.28\a.cpp
 * @LastEditTime: 2021-09-28 19:59:09
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

int n;
const int N = 1e4 + 10;
int a[N], b[N];
unordered_map<int, int> m;
signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        m[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        m[b[i]] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (m[a[i] ^ b[j]])
            {
                ans++;
            }
        }
    }
    //DEBUG(ans);
    if (ans & 1)
        cout << "Koyomi" << '\n';
    else
        cout << "Karen" << '\n';
    return 0;
}