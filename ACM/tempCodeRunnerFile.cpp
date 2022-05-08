#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>

#define int long long
#define SZ(X) ((int)X.size())

using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    vector<int> c;
    int l = 0, r = 0;
    while (l < n || r < m)
    {
        if (r == m || (l < n && a[l] < b[r]))
        {
            c.push_back(a[l]);
            l++;
        }
        else
        {
            c.push_back(b[r]);
            r++;
        }
    }
    cout << c[(SZ(c) - 1) / 2];
    return 0;
}