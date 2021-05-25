#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wwork(int n, vector<int>& a) {
        int mn = n + 1, ans = 0;
        for (int i = n - 1; ~i; --i) {
            if (a[i] < mn) mn = a[i];
            else ++ans;
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    vector < int > v = {4, 1, 2, 3};
    int ans = solution.wwork(4, v);
    cout << ans << endl;
    return 0;
}