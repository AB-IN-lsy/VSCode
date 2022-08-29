/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-23 10:24:23
 * @FilePath: \LeetCode\1282\1282.cpp
 * @LastEditTime: 2022-08-23 10:24:31
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
#define SZ(X) ((int)(X).size())
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;
        int n = SZ(groupSizes);
        vector<int> g[n + 1];
        for (int i = 0; i < n; ++i)
        {
            g[groupSizes[i]].push_back(i);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (SZ(g[i]))
            {
                vector<int> a;
                for (int j = 0; j < SZ(g[i]); ++j)
                {
                    a.push_back(g[i][j]);
                    if ((j + 1) % i == 0)
                    {
                        ans.push_back(a);
                        a.clear();
                    }
                }
            }
        }
        return ans;
    }
};
signed main()
{
    IOS;

    return 0;
}