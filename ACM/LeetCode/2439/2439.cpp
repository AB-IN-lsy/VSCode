/*
 * @Author: NEFU AB-IN
 * @Date: 2022-10-24 15:17:09
 * @FilePath: \LeetCode\2439\2439.cpp
 * @LastEditTime: 2022-10-24 15:38:07
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

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int l = 0, r = *max_element(nums.begin(), nums.end());

        auto check = [&](int x) {
            int sum = 0; // 可承载量
            for (auto num : nums)
            {
                if (num < x)
                    sum += x - num;
                else
                {
                    if (sum < num - x)
                        return false;
                    sum -= num - x;
                }
            }
            return true;
        };

        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

// ---------------------

signed main()
{
    Solution solution;
    vector<int> a = {3, 7, 1, 6};
    solution.minimizeArrayValue(a);
    return 0;
}