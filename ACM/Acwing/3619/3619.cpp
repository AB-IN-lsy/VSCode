#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << endl
typedef pair<int, int> PII;

signed main()
{
    IOS;

    unordered_map<int, string> mp = {{1, "Monday"}, {2, "Tuesday"},  {3, "Wednesday"}, {4, "Thursday"},
                                     {5, "Friday"}, {6, "Saturday"}, {7, "Sunday"}};
    vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    cin >> m >> d;

    int s = 12;
    int e = 0;
    for (int i = 4; i < m; ++i)
        e += month[i];
    e += d;

    int ans = (e - s + 3) % 7 + 1;
    cout << mp[ans];

    return 0;
}