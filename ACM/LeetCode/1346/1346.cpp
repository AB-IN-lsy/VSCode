/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-29 22:51:16
 * @FilePath: \LeetCode\1346\1346.cpp
 * @LastEditTime: 2022-08-29 22:52:55
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
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (auto x : arr)
        {
            mp[x]++;
        }
        if (mp[0] > 1)
            return true;
        for (auto [id, val] : mp)
        {
            if (id && mp.count(id * 2))
            {
                return true;
            }
        }
        return false;
    }
};

// ---------------------

signed main()
{
    Solution solution;
    vector<int> a = {0, 0};
    solution.checkIfExist(a);
    return 0;
}