/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-22 17:19:54
 * @FilePath: \ACM\GPLT\L1-078.CPP
 * @LastEditTime: 2022-04-22 19:04:23
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

int n, m, flag = 0;
signed main()
{
    cin >> n >> m;
    getchar();
    string s;
    string t1 = "qiandao", t2 = "easy";
    for (int i = 1; i <= n; ++i)
    {
        getline(cin, s);
        if (strstr(s.c_str(), t1.c_str()) || strstr(s.c_str(), t2.c_str()))
            continue;
        m -= 1;
        if (m < 0 && !flag)
        {
            flag = 1;
            cout << s << '\n';
        }
    }
    if (!flag)
        cout << "Wo AK le\n";
    return 0;
}