/*
 * @Author: NEFU AB-IN
 * @Date: 2022-05-12 20:38:07
 * @FilePath: \ACM\Acwing\1541.cpp
 * @LastEditTime: 2022-05-15 21:35:50
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

const int N = 210;

struct sa
{
    string name;
    int age, w;
};

signed main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    vector<sa> a[N];

    for (int i = 0; i < n; ++i)
    {
        string name;
        int age, w;
        cin >> name >> age >> w;
        a[age].push_back({name, age, w});
    }
    for (int i = 0; i < N; ++i)
    {
        sort(a[i].begin(), a[i].end(), [&](sa a, sa b) {
            if (a.w != b.w)
                return a.w > b.w;
            else if (a.age != b.age)
                return a.age < b.age;
            return a.name < b.name;
        });
    }
    // 堆的比较函数，正好反过来
    auto cmp = [&](sa a, sa b) {
        if (a.w != b.w)
            return a.w < b.w;
        else if (a.age != b.age)
            return a.age > b.age;
        return a.name > b.name;
    };
    // 多路合并
    for (int C = 1; C <= k; ++C)
    {
        int m, l, r;
        cin >> m >> l >> r;
        printf("Case #%lld:\n", C);

        vector<int> idx(N);
        // decltype(cmp)获得函数指针 的类型
        priority_queue<sa, vector<sa>, decltype(cmp)> q(cmp);
        // 初始化，先放入所有的路的top
        for (int i = l; i <= r; ++i)
        {
            if (SZ(a[i]) > idx[i])
                q.push(a[i][idx[i]++]);
        }
        if (!SZ(q))
        {
            printf("None\n");
            continue;
        }
        int cnt = 0;
        while (SZ(q) && cnt < m)
        {
            sa top = q.top();
            q.pop();
            printf("%s %lld %lld\n", top.name.c_str(), top.age, top.w);
            cnt++;
            if (SZ(a[top.age]) > idx[top.age])
                q.push(a[top.age][idx[top.age]++]);
        }
    }
    return 0;
}