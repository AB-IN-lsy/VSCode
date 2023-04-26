#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

void solve(string s)
{
    int cnt = 0, st = 0, flag = 0;
    int ans_len = 0, ans_st = 0;
    string t = "";
    for (int i = 0; i < s.length(); ++i)
    {

        if (s[i] >= '0' && s[i] <= '9' && flag == 0)
        {
            flag = 1;
            st = i;
            cnt = 1;
            ans_len = max(ans_len, cnt);
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            cnt++;
            if (cnt > ans_len)
            {
                ans_len = cnt;
                ans_st = st;
            }
        }
        else
        {
            cnt = 0;
            flag = 0;
        }
    }

    cout << s.substr(ans_st, ans_len) << '\n';
    cout << ans_len << '\n';
}

signed main()
{
    IOS;
    solve("a123123da1sd");
    return 0;
}