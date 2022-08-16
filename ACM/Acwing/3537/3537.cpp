/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-10 21:34:43
 * @FilePath: \Acwing\3537\3537.cpp
 * @LastEditTime: 2022-08-10 22:15:38
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int n;
    cin >> n;

    vector<int> a(n + 1);
    int k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    cin >> k;

    int s = pow(2, k - 1);
    if (s > n)
        cout << "EMPTY";
    else
    {
        for (int i = s; i <= min(n, 2 * s - 1); ++i)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}