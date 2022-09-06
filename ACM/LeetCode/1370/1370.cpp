/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-06 16:29:26
 * @FilePath: \LeetCode\1370\1370.cpp
 * @LastEditTime: 2022-09-06 18:36:55
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define int long long
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
    string sortString(string s)
    {
        map<char, int> counter;
        for (auto i : s)
            counter[i]++;
        int flag = 0;
        string ans;
        while (SZ(ans) < SZ(s))
        {
            string tmp;
            for (auto [c, cnt] : counter)
            {
                if (counter[c])
                {
                    tmp += c;
                    counter[c]--;
                }
            }
            if (flag)
                reverse(tmp.begin(), tmp.end());
            ans += tmp;
            flag ^= 1;
        }
        return ans;
    }
};

#undef int
// ---------------------

signed main()
{
    Solution solution;
    solution.sortString("leetcode");
    return 0;
}