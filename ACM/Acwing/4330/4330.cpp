/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-23 10:47:57
 * @FilePath: \ACM\Acwing\4330\4330.cpp
 * @LastEditTime: 2022-06-23 11:02:27
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int T;

    cin >> T;

    while (T--)
    {
        vector<int> a(4), b(4);
        for (int i = 0; i < 4; i++)
            cin >> a[i];
        for (int i = 0; i < 4; i++)
            cin >> b[i];

        auto compare = [&](vector<int> a, vector<int> b) {
            int win = 0, lose = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if (a[i] > b[j])
                        win++;
                    else if (a[i] < b[j])
                        lose++;
            return win > lose;
        };

        auto check = [&]() {
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                    for (int k = 1; k <= 10; k++)
                        for (int u = 1; u <= 10; u++)
                        {
                            vector<int> c = {i, j, k, u};
                            if (compare(a, b) && compare(b, c) && compare(c, a))
                                return true;
                            if (compare(b, a) && compare(a, c) && compare(c, b))
                                return true;
                        }

            return false;
        };

        if (check())
            puts("yes");
        else
            puts("no");
    }

    return 0;
}