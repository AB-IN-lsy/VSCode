/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-22 15:07:41
 * @FilePath: \ACM\GPLT\L1-069.cpp
 * @LastEditTime: 2022-04-22 16:16:49
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

int mn, leap;

signed main()
{
    IOS;
    vector<int> v(4);
    for (int i = 0; i < 4; ++i)
    {
        cin >> v[i];
    }
    cin >> mn >> leap;
    int mx = *max_element(v.begin(), v.end());
    int ans = -1, cnt = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (mx - v[i] > leap && mx - v[i] < mn)
        {
            ans = i + 1;
            cnt++;
        }
    }
    if (ans == -1)
        cout << "Normal\n";
    else if (cnt > 1)
        cout << "Warning: please check all the tires!\n";
    else
        printf("Warning: please check #%lld!", ans);
    return 0;
}