#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
unordered_map<string, vector<int>> v;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    int cnt = 0, ans = 0;
    while (cin >> s)
    {
        ans += v[s].size() - (lower_bound(v[s].begin(), v[s].end(), cnt - k) - v[s].begin());
        v[s].push_back(++cnt);
    }

    cout << ans << '\n';
}