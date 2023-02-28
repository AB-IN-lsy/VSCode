/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-18 18:59:30
 * @FilePath: \Acwing\91cp\a\a.cpp
 * @LastEditTime: 2023-02-18 19:03:25
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        vector<int> ans;
        while (n)
        {
            int k = n % 10;
            int x = k * pow(10, cnt);
            if (x)
                ans.push_back(x);
            n /= 10;
            cnt++;
        }
        cout << SZ(ans) << '\n';
        for (auto i : ans)
            cout << i << " ";
        cout << '\n';
    }
    return 0;
}