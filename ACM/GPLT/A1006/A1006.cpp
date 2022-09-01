/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-31 20:40:42
 * @FilePath: \GPLT\A1006\A1006.cpp
 * @LastEditTime: 2022-08-31 20:48:28
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

signed main()
{
    IOS;
    int n;
    cin >> n;
    struct sa
    {
        string id;
        string si, so;
    };
    vector<sa> d(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i].id >> d[i].si >> d[i].so;
    }
    sort(d.begin(), d.end(), [&](sa a, sa b) { return a.si < b.si; });
    cout << d[0].id << " ";
    sort(d.begin(), d.end(), [&](sa a, sa b) { return a.so > b.so; });
    cout << d[0].id;

    return 0;
}