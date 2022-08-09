/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-08 00:33:59
 * @FilePath: \Acwing\3438\test.cpp
 * @LastEditTime: 2022-08-09 20:29:03
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

char itoc(int x)
{
    if (x < 10)
        return '0' + x;
    return 'A' + x - 10;
}

int ctoi(char c)
{
    if (c <= '9')
        return c - '0';
    if (c <= 'Z')
        return c - 'A' + 10;
    return c - 'a' + 10;
}

signed main()
{
    IOS;
    string n;
    int a, b;
    cin >> a >> n >> b;

    // a进制转10进制
    int ans = 0;
    for (auto i : n)
    {
        ans = ans * a + ctoi(i);
    }
    // 10进制转b进制
    string res;
    while (ans)
    {
        res += itoc(ans % b);
        ans /= b;
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
    return 0;
}
