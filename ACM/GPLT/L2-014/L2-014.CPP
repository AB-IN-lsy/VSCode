/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-21 10:44:29
 * @FilePath: \ACM\GPLT\L2-014.CPP
 * @LastEditTime: 2022-04-21 11:27:17
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e5 + 10;
deque<int> q[N];

int n, id, cnt;
unordered_map<int, int> pos;

signed main()
{
    IOS;
    cin >> n;
    int ans = 1, m = n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (id > 0 && (SZ(q[id]) == 0 || x < q[id].front()))
        {
            q[id].push_front(x);
        }
        else
        {
            id++;
            q[id].push_front(x);
            cnt += 1;
            pos[x] = id;
        }
        ans = max(ans, cnt);
        // pos[che] = guiDao
        if (pos[m])
        {
            q[pos[m]].pop_back();
            if (SZ(q[pos[m]]))
            {
                pos[q[pos[m]].back()] = pos[m];
            }
            else
            {
                cnt -= 1;
            }
            pos[m] = 0;
            m -= 1;
        }
    }
    cout << ans;
    return 0;
}