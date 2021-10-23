/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-13 19:53:16
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.13\a.cpp
 * @LastEditTime: 2021-09-13 20:13:32
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

signed main()
{
    IOS;
    int n = 24;
    vector<LL> v1, v2;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v1.push_back(i);
            if (n % i != i)
                v1.push_back(n / i);
        }
    }
    for (auto a : v1)
        cout << a << ' ';
    cout << '\n';
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            n /= i;
            v2.push_back(i);
        }
    }
    if (n > 1)
        v2.push_back(n);
    for (auto a : v2)
        cout << a << ' ';
    cout << '\n';
    return 0;
}