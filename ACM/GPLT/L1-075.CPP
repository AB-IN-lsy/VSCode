/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-22 16:45:11
 * @FilePath: \ACM\GPLT\L1-075.CPP
 * @LastEditTime: 2022-04-22 17:06:26
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
    string s, year, month;
    cin >> s;
    if (SZ(s) == 6)
    {
        year = s.substr(0, 4);
        month = s.substr(4, 2);
        printf("%s-%s", year.c_str(), month.c_str());
    }
    else
    {
        year = s.substr(0, 2);
        month = s.substr(2, 2);
        int y = stoll(year);
        if (y < 22)
            printf("20%s-%s", year.c_str(), month.c_str());
        else
            printf("19%s-%s", year.c_str(), month.c_str());
    }
    return 0;
}