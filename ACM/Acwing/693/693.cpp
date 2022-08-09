/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-04 16:35:04
 * @FilePath: \Acwing\693\693.cpp
 * @LastEditTime: 2022-08-04 17:01:30
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_)
    {
        int n;
        cin >> n;
        map<string, string> st;
        map<string, int> deg;
        set<string> se;
        for (int i = 1; i <= n; ++i)
        {
            string s, t;
            cin >> s >> t;
            st[s] = t;
            deg[t]++;
            se.insert(s), se.insert(t);
        }

        string s;
        for (auto c : se)
        {
            if (!deg[c])
                s = c;
        }
        printf("Case #%lld: ", _);

        while (st.count(s))
        {
            printf("%s-%s ", s.c_str(), st[s].c_str());
            s = st[s];
        }
        puts("");
    }
    return 0;
}