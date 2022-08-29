/*
 * @Author: NEFU AB-IN
 * @Date: 2021-07-16 18:21:26
 * @FilePath: \LeetCode\1004\main.cpp
 * @LastEditTime: 2022-08-23 08:53:18
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int longestOnes(vector<int> &A, int K)
    {
        int p1 = 0, p2 = 0, cnt = 0, ans = -1;
        while (p1 <= p2 && p2 < A.size())
        {
            cnt += (A[p2] == 0);
            if (cnt > K)
            {
                cnt -= (A[p1] == 0);
                p1++;
            }
            p2++;
            ans = max(ans, p2 - p1);
        }
        return ans;
    }
};
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
int n, k, c;
int main()
{
    Solution solution;
    cin >> n >> k;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        a.push_back(c);
    }
    cout << solution.longestOnes(a, k) << endl;
    return 0;
}
