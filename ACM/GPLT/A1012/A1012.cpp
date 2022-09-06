/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-02 21:22:49
 * @FilePath: \GPLT\A1012\A1012.cpp
 * @LastEditTime: 2022-09-03 14:36:55
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

int get_rank(vector<int> &a, int x)
{
    int l = 0, r = SZ(a) - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return SZ(a) - r;
}

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(4, vector<int>(n)), v1(n, vector<int>(4)); // A: q[0], C: q[1], M: q[2], E: q[3]
    vector<string> id(n);
    unordered_map<string, int> st;

    for (int i = 0; i < n; ++i)
    {
        cin >> id[i];
        st[id[i]] = i;
        double sum = 0;
        for (int j = 1; j < 4; ++j)
        {
            cin >> v1[i][j];
            v[j][i] = v1[i][j];
            sum += v1[i][j];
        }
        v1[i][0] = round(sum / 3.0);
        v[0][i] = v1[i][0];
    }
    for (int i = 0; i < 4; ++i)
    {
        sort(v[i].begin(), v[i].end());
    }
    string s = "ACME";

    for (int i = 0; i < m; ++i)
    {
        string id;
        cin >> id;
        if (!st.count(id))
        {
            cout << "N/A\n";
            continue;
        }
        int index = st[id], mn = INT_MAX, ans_id = 0;
        for (int j = 0; j < 4; ++j)
        {
            int grade = v1[index][j];
            int rank = get_rank(v[j], grade);
            if (rank < mn)
            {
                mn = rank;
                ans_id = j;
            }
        }
        cout << mn << " " << s[ans_id] << '\n';
    }

    return 0;
}