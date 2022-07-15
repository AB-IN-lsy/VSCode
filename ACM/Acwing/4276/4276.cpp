/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-21 10:36:20
 * @FilePath: \ACM\Acwing\4276\4276.cpp
 * @LastEditTime: 2022-06-21 10:48:27
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
string a[26][7];

signed main()
{
    string s;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> s;
            a[i][j] = s;
        }
    }
    getchar();
    getline(cin, s);
    string str;
    vector<string> c;
    for (int i = 0; i < s.size(); i++)
    {
        str = "";
        while (s[i] >= 'A' && s[i] <= 'Z')
        {
            str += s[i];
            i++;
        }
        if (str != "")
            c.push_back(str);
    }

    for (int i = 0; i < c.size(); i++)
    {
        if (i)
            puts("");
        string res[7] = {};
        for (int j = 0; j < c[i].size(); j++)
        {
            for (int z = 0; z < 7; z++)
            {
                int ch = c[i][j] - 'A';
                res[z] += a[ch][z] + " ";
            }
        }
        for (int z = 0; z < 7; z++)
        {
            res[z].pop_back();
            cout << res[z] << endl;
        }
    }
    return 0;
}