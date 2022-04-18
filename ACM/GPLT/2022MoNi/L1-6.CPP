/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-18 19:52:40
 * @FilePath: \ACM\GPLT\L1-6.CPP
 * @LastEditTime: 2022-04-18 19:52:40
 */
/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-13 21:51:51
 * @FilePath: \ACM\GPLT\tmp.cpp
 * @LastEditTime: 2022-04-18 19:51:56
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

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int flag = 0;
        for (int i = 0; i < SZ(s) - 1; ++i)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                if (s[i] == 'Z' && s[i] + 32 != s[i + 1])
                    flag = 1;
                else if (s[i] + 32 != s[i + 1] && s[i] + 1 != s[i + 1])
                    flag = 1;
            }
            else
            {
                if (s[i] == 'a' && s[i] - 32 != s[i + 1])
                    flag = 1;
                else if (s[i] - 32 != s[i + 1] && s[i] - 1 != s[i + 1])
                    flag = 1;
            }
            if (flag)
                break;
        }
        if (flag)
            puts("N");
        else
            puts("Y");
    }
    return 0;
}