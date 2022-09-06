/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-05 20:35:38
 * @FilePath: \LeetCode\1343\1343.cpp
 * @LastEditTime: 2022-09-05 20:47:00
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
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int n = SZ(arr);
        vector<int> b(arr), c(n + 1);
        b.insert(b.begin(), 0);

        for (int i = 1; i <= n; ++i)
        {
            c[i] = c[i - 1] + b[i];
        }
        int ans = 0;
        for (int l = 1, r = k; r <= n; ++l, ++r)
        {
            if ((double)(c[r] - c[l - 1]) / k >= threshold)
                ans++;
        }
        return ans;
    }
};

// ---------------------

signed main()
{
    Solution solution;
    return 0;
}