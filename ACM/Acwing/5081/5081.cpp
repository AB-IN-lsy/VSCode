/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-23 17:28:10
 * @FilePath: \Acwing\5081\5081.cpp
 * @LastEditTime: 2023-08-23 19:16:21
 */
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

unordered_map <string, int> st;

signed main()
{
    //freopen("Tests/input_1.txt", "r", stdin);
    IOS;
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; ++ i){
        string s;
        for(int i = 1; i <= 8; ++ i){
            string ss;
            getline(cin, ss);
            s += ss;
        }
        st[s] += 1;
        cout << st[s] << '\n';
    }
    return 0;
}
