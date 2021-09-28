/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-28 23:39:42
 * @FilePath: \ACM\CF\2021.9.28.div3\e1.cpp
 * @LastEditTime: 2021-09-28 23:41:59
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
const int N = 2e5 + 10;
int s[N];
int t;
deque<int> q;

signed main()
{
    IOS;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i == 0)
            {
                q.push_back(x);
                continue;
            }
            if (*(q.begin()) >= x)
                q.push_front(x);
            else
                q.push_back(x);
        }
        for (auto i : q)
            cout << i << " ";
        cout << '\n';
        q.clear();
    }

    return 0;
}