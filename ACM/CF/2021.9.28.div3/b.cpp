/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-28 22:44:40
 * @FilePath: \ACM\CF\2021.9.28.div3\b.cpp
 * @LastEditTime: 2021-09-28 23:19:14
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 100;
int a[N];

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            q.push(MP(a[i], i));
        }
        cout << n << '\n';
        int l = 1, r = n, re = 0;
        while (q.size())
        {
            PII tmp = q.top();
            q.pop();
            cout << l << " " << r << " " << (tmp.second - l - re + r - l + 1) % (r - l + 1) << '\n';
            re += (tmp.second - l - re + r - l + 1) % (r - l + 1);
            l++;
        }
    }
    return 0;
}