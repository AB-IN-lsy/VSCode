/*
 * @Author: NEFU AB-IN
 * @Date: 2022-01-15 13:16:36
 * @FilePath: \ACM\ACnowcoder\2022.1.15\c.cpp
 * @LastEditTime: 2022-01-15 13:18:54
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int cnt;
namespace Kmp
{
const int N = 1E7 + 10;
string t;
int Next[N];
void get_next(string t)
{
    int i = 0, j = -1;
    int n = t.length();
    Next[0] = -1;
    while (i < n)
    {
        if (j == -1 || t[i] == t[j])
        {
            i++, j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}
int kmp(string s, string ss)
{
    int i = 0, j = 0;
    int slen = s.length(), sslen = ss.length();
    get_next(ss);
    while (i < slen && j < sslen)
    {
        if (j == -1 || s[i] == ss[j])
        {
            if (j == sslen - 1)
            {
                j = 0;
                cnt += 1;
                i++;
            }
            else
            {
                i++, j++;
            }
        }
        else
            j = Next[j];
    }
    if (j == sslen)
        return 1;
    else
        return -1;
    return 0;
}
} // namespace Kmp
using namespace Kmp;

signed main()
{
    IOS;
    string s, ss;
    cin >> s >> ss;
    kmp(s, ss);
    if (cnt)
    {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}