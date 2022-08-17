/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 15:25:52
 * @FilePath: \Acwing\3589\3589.cpp
 * @LastEditTime: 2022-08-17 15:38:10
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
    while (cin >> n)
    {
        vector<int> a;
        for (int i = 1; i <= n / i; ++i)
        {
            if (n % i == 0)
            {
                a.push_back(i);
                if (n / i != i)
                    a.push_back(n / i);
            }
        }
        auto check = [&](int x) {
            int s = sqrt(x);
            return s * s == x;
        };
        int flag = 0;
        for (auto i : a)
        {
            if (i != 1 && check(i))
            {
                flag = 1;
                cout << "Yes\n";
                break;
            }
        }
        if (!flag)
            cout << "No\n";
    }
    return 0;
}