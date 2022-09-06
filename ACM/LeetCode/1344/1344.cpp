/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-05 20:55:57
 * @FilePath: \LeetCode\1344\1344.cpp
 * @LastEditTime: 2022-09-05 21:07:27
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define SZ(X) ((int)(X).size())
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

// #undef int;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    double angleClock(int hour, int minutes)
    {
        double h = (30.0 * hour + 0.5 * minutes);
        double m = minutes * 6;
        double ans = h - m;
        if (ans < 0)
            ans += 360;

        return min(ans, 360 - ans);
    }
};

// ---------------------

signed main()
{
    Solution solution;
    return 0;
}