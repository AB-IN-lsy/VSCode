/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-23 08:52:05
 * @FilePath: \LeetCode\768\768.cpp
 * @LastEditTime: 2022-08-23 10:24:20
 */
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define SZ(X) ((int)(X).size())

class Solution
{
  public:
    int maxChunksToSorted(vector<int> &arr)
    {
        stack<int> s;
        for (auto i : arr)
        {
            if (!SZ(s) || i >= s.top())
                s.push(i);
            else
            {
                int mx = s.top();
                s.pop();
                while (SZ(s) && s.top() > i)
                    s.pop();
                s.push(mx);
            }
        }
        return SZ(s);
    }
};

signed main()
{

    return 0;
}