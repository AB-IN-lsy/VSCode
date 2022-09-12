/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-09 14:13:18
 * @FilePath: \LeetCode\1386\1386.cpp
 * @LastEditTime: 2022-09-09 16:22:54
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
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        bitset<11> left{0b111100000}, mid{0b1111000}, right{0b11110};

        // 2~5 4~7 6~9
        unordered_map<int, bitset<11>> mp;
        for (auto v : reservedSeats)
        {
            int h = v[0], l = v[1];
            if (l >= 2 && l <= 9)
            {
                mp[h].set(10 - l);
            }
        }
        int ans = (n - SZ(mp)) * 2;
        for (auto [h, b] : mp)
        {
            b = ~b;
            // DEBUG(right);
            if (((b & left) == left) || ((b & right) == right) || ((b & mid) == mid))
                ans++;
        }
        return ans;
    }
};

// ---------------------

// signed main()
// {
//     Solution solution;
//     vector<vector<int>> a = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
//     cout << solution.maxNumberOfFamilies(3, a);
//     return 0;
// }