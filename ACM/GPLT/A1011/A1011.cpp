/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-02 21:03:13
 * @FilePath: \GPLT\A1011\A1011.cpp
 * @LastEditTime: 2022-09-02 21:04:25
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
    double res = 1;
    for (int i = 0; i < 3; i++)
    {
        double w, t, l;
        cin >> w >> t >> l;
        double x = max(w, max(t, l));
        if (x == w)
            cout << "W ";
        else if (x == t)
            cout << "T ";
        else
            cout << "L ";
        res *= x;
    }

    printf("%.2lf\n", (res * 0.65 - 1) * 2);

    return 0;
}