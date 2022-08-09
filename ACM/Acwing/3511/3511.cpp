/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-09 20:41:11
 * @FilePath: \Acwing\3511\3511.cpp
 * @LastEditTime: 2022-08-09 21:44:52
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
const int B = 10000;

signed main()
{
    IOS;
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        unordered_set<int> st; // 记录A,B,C状态
        unordered_set<int> s;  // 记录C的状态

        vector<int> x = {0, 0, c};      // 初始状态
        vector<int> bottle = {a, b, c}; // 瓶子容量

        function<int(vector<int>)> get = [&](vector<int> x) {
            return x[0] * B * B + x[1] * B + x[2];
        }; // 将瓶子的状态转换为long long 型

        function<void(vector<int>)> dfs = [&](vector<int> x) {
            st.insert(get(x));
            s.insert(x[2]);

            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (i != j)
                    {
                        vector<int> tmp(x);
                        // 倒水，从i往j倒
                        int water = min(tmp[i], bottle[j] - tmp[j]);
                        tmp[i] -= water;
                        tmp[j] += water;
                        if (!st.count(get(tmp)))
                            dfs(tmp);
                    }
                }
            }
        };

        dfs(x);

        cout << SZ(s) << '\n';
    }
    return 0;
}