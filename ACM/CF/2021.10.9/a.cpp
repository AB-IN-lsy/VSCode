/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-09 16:20:21
 * @FilePath: \ACM\CF\2021.10.9\a.cpp
 * @LastEditTime: 2021-10-09 17:09:04
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

unordered_map<string, int> xianhou;
unordered_map<string, int> cnt;

struct sa
{
    string s;
    int xianhou, cnt;

    bool operator<(const sa &a) const
    {
        if (cnt != a.cnt)
            return cnt > a.cnt;
        else
            return xianhou > a.xianhou;
    }
    sa(string s, int xianhou, int cnt) : s(s), xianhou(xianhou), cnt(cnt){};
};

signed main()
{
    IOS;
    int n, k;
    string s;
    cin >> n >> k;
    getline(cin, s);
    for (int i = 1; i <= 3 * n; ++i)
    {
        getline(cin, s);
        cnt[s]++;
        xianhou[s] = i;
    }
    vector<sa> v;
    for (auto [a, b] : xianhou)
    {
        v.emplace_back(sa(a, b, cnt[a]));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < min(k, SZ(v)); ++i)
    {
        cout << v[i].s << '\n';
    }
    return 0;
}