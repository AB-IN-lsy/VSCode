/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-27 16:06:31
 * @FilePath: \ACM\Acwing\4367\4367.cpp
 * @LastEditTime: 2022-06-27 16:51:35
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

signed main()
{
    IOS;
    int n, a;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    set<int> st;
    for (int i = 0, j = 0; i < n; i++)
    {
        cin >> a;
        while (st.count(b[j]))
            j++;
        if (b[j] == a)
            j++;
        else
            st.insert(a);
    }
    cout << st.size() << "\n";
    return 0;
}