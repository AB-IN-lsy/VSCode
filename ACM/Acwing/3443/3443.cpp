/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-02 16:20:07
 * @FilePath: \Acwing\3443\3443.cpp
 * @LastEditTime: 2023-01-02 16:50:36
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

// #undef N
// const int N = 1e5 + 10;

// #undef int

double get_score(int x) // 计算绩点
{
    if (x >= 90 && x <= 100)
        return 4.0;
    else if (x >= 85)
        return 3.7;
    else if (x >= 82)
        return 3.3;
    else if (x >= 78)
        return 3.0;
    else if (x >= 75)
        return 2.7;
    else if (x >= 72)
        return 2.3;
    else if (x >= 68)
        return 2.0;
    else if (x >= 64)
        return 1.5;
    else if (x >= 60)
        return 1.0;
    else
        return 0;
}

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> x(n), score(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> score[i];

    double res = 0;
    int sum = accumulate(x.begin(), x.end(), 0);
    for (int i = 0; i < n; ++i)
    {
        res += get_score(score[i]) * x[i];
    }
    printf("%.2lf", res / sum);
    return 0;
}