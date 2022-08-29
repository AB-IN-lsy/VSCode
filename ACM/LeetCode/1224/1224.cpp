/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-24 15:23:44
 * @FilePath: \LeetCode\1224\1224.cpp
 * @LastEditTime: 2022-08-24 20:57:46
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

class Solution
{
  public:
    int maxEqualFreq(vector<int> &nums)
    {
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count[nums[i]] > 0)
            {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = maxFreq == 1 ||
                      freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
                      freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
            if (ok)
            {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};
signed main()
{
    IOS;
    Solution solution;

    vector<int> a = {1, 1, 1, 2, 2, 2};
    cout << solution.maxEqualFreq(a) << endl;
    return 0;
}