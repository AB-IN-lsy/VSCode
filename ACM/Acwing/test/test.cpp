/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-30 11:32:05
 * @FilePath: \Acwing\test\test.cpp
 * @LastEditTime: 2023-07-17 08:30:46
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

std::string solution(int num)
{
    std::string s = "";

    while (num > 0)
    {
        int r = (num - 1) % 26;
        char l = 'A' + r;
        s = l + s;
        num = (num - 1) / 26;
    }

    return s;
}

class Solution
{
  public:
    int maxSubArray(std::vector<int> &nums)
    {
        // 请实现函数
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
                dp[i] = max(0, nums[i]);
            else
                dp[i] = max(0, dp[i - 1] + nums[i]);
        }
        int mx = dp[0];
        for (auto i : dp)
        {
            mx = max(mx, i);
        }
        return mx;
    }
};

signed main()
{
    IOS;
    cout << solution(700) << '\n';
    cout << solution(30) << '\n';
    cout << solution(28) << '\n';
    cout << solution(27) << '\n';
    cout << solution(26) << '\n';
    cout << solution(24) << '\n';
    cout << solution(1) << '\n';

    Solution solution;
    vector<int> v{1, -2, 3, 10, -4, 7, 2, -5};
    cout << solution.maxSubArray(v);
    return 0;
}