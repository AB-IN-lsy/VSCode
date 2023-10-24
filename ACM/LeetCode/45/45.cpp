/*
 * @Author: NEFU AB-IN
 * @Date: 2023-09-15 10:36:39
 * @FilePath: \LeetCode\45\45.cpp
 * @LastEditTime: 2023-09-15 10:38:09
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define LL long long
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}();

class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        const int n = nums.size();
        int ans = 0, cur = 0, dis = 0;

        while (dis < n - 1)
        {
            int next = 0;
            while (cur <= dis)
            {
                next = max(next, cur + nums[cur]);
                cur++;
            }

            ans++;
            dis = next;
        }

        return ans;
    }
};

// ---------------------

signed main()
{
    // freopen("Tests/input_1.txt", "r", stdin);
    Solution solution;

    vector<int> v{2, 3, 1, 1, 4};
    cout << solution.jump(v);
    return 0;
}