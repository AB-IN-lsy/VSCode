/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-30 17:30:54
 * @FilePath: \LeetCode\1329\1329.cpp
 * @LastEditTime: 2022-09-05 20:24:54
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
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int h = SZ(mat), l = SZ(mat[0]);
        for (int i = h - 1; i >= 0; --i)
        {
            int ch = i, cl = 0;
            vector<int> a;
            while (ch < h && cl < l)
            {
                a.push_back(mat[ch++][cl++]);
            }
            sort(a.begin(), a.end());
            ch = i, cl = 0;
            int idx = 0;
            while (ch < h && cl < l)
            {
                mat[ch++][cl++] = a[idx++];
            }
        }
        for (int i = 1; i < l; ++i)
        {
            int ch = 0, cl = i;
            vector<int> a;
            while (ch < h && cl < l)
            {
                a.push_back(mat[ch++][cl++]);
            }
            sort(a.begin(), a.end());
            ch = 0, cl = i;
            int idx = 0;
            while (ch < h && cl < l)
            {
                mat[ch++][cl++] = a[idx++];
            }
        }
        return mat;
    }
};

// ---------------------

signed main()
{
    Solution solution;
    vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    solution.diagonalSort(mat);
    return 0;
}