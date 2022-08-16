/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-13 19:00:00
 * @FilePath: \64cp\A\A.cpp
 * @LastEditTime: 2022-08-13 19:19:42
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
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
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        auto judge = [&](string s) {
            cout << s.substr(SZ(s) - 2, 2) << '\n';
            if (SZ(s) > 2 && s.substr(SZ(s) - 2, 2) == "po")
                return 1;
            if (SZ(s) > 4 && (s.substr(SZ(s) - 4, 4) == "desu" || s.substr(SZ(s) - 4, 4) == "masu"))
                return 2;
            if (SZ(s) > 5 && s.substr(SZ(s) - 5, 5) == "mnida")
                return 3;
        };
        int k = judge(s);

        if (k == 1)
            cout << "FILIPINO\n";
        if (k == 2)
            cout << "JAPANESE\n";
        if (k == 3)
            cout << "KOREAN\n";
    }
    return 0;
}