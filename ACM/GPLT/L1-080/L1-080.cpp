/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-22 19:22:10
 * @FilePath: \ACM\GPLT\L1-080.cpp
 * @LastEditTime: 2022-04-22 19:30:12
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

int a1, a2, n;
vector<int> v;

void cale(int x)
{
    vector<int> tmp;
    while (x)
    {   
        tmp.push_back(x % 10);
        x /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    v.insert(v.end(), tmp.begin(), tmp.end());
}

signed main()
{
    IOS;
    cin >> a1 >> a2 >> n;
    v.push_back(a1);
    v.push_back(a2);
    int p1 = 0, p2 = 1;
    while (SZ(v) < n)
    {
        int x = v[p1], y = v[p2];
        int ans = x * y;
        cale(ans);
        p1++;
        p2++;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << " "[i == n - 1];
    }
    return 0;
}