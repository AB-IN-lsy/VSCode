/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-29 10:31:32
 * @FilePath: \LeetCode\1450\1450.cpp
 * @LastEditTime: 2022-08-29 10:38:34
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define SZ(X) ((int)(X).size())
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        vector<int> b(1100);
        for (int i = 0; i < SZ(startTime); ++i)
        {
            b[startTime[i]]++;
            b[endTime[i] + 1]--;
        }
        for (int i = 1; i < 1100; ++i)
        {
            b[i] += b[i - 1];
        }
        return b[queryTime];
    }
};

// ---------------------

signed main()
{
    Solution solution;
    return 0;
}