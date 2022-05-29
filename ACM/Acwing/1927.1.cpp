/*
 * @Author: NEFU AB-IN
 * @Date: 2022-05-23 14:49:10
 * @FilePath: \ACM\Acwing\1927.1.cpp
 * @LastEditTime: 2022-05-23 14:49:15
 */
#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
#define x first
#define y second

typedef pair<string, int> PSI;

const int N = 1e6 + 10;

signed main()
{
    IOS;
    int w, n;
    cin >> w >> n;
    vector<PSI> a(w);
    for (int i = 0; i < w; ++i)
    {
        cin >> a[i].x;
        a[i].y = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; ++i)
    {
        int num;
        string pre;
        cin >> num >> pre;

        int l = 0, r = w - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid].x >= pre)
                r = mid;
            else
                l = mid + 1;
        }

        int idx = l + num - 1;
        if (idx >= w || a[idx].x.substr(0, SZ(pre)) != pre)
        {
            cout << "-1\n";
        }
        else
            cout << a[idx].y << '\n';
    }
    return 0;
}