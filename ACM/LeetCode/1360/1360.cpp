/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-06 14:32:38
 * @FilePath: \LeetCode\1360\1360.cpp
 * @LastEditTime: 2022-09-06 16:13:27
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int daysBetweenDates(string date1, string date2)
    {
        if (date1 > date2)
            swap(date1, date2);
        int y1, m1, d1, y2, m2, d2;

        sscanf(date1.c_str(), "%lld-%lld-%lld", &y1, &m1, &d1);
        sscanf(date2.c_str(), "%lld-%lld-%lld", &y2, &m2, &d2);

        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto check = [&](int y) { return y % 400 == 0 || (y % 100 && y % 4 == 0); };

        auto f = [&](vector<int> months, int y, int m, int d) {
            if (check(y))
                months[2]++;
            int x = d;
            for (int i = 1; i <= m - 1; ++i)
                x += months[i];
            return x;
        };

        int x1 = 365 + check(y1) - f(months, y1, m1, d1);
        int x2 = f(months, y2, m2, d2);

        int x3 = 0;
        for (int i = y1 + 1; i <= y2 - 1; ++i)
        {
            x3 += (365 + check(i));
        }
        int ans = x1 + x2 + x3;
        if (y1 == y2)
            ans %= (365 + check(y1));
        return ans;
    }
};

#undef int;
// ---------------------

signed main()
{
    Solution solution;
    return 0;
}