/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-13 15:29:56
 * @FilePath: \Acwing\3601\3601.cpp
 * @LastEditTime: 2022-08-13 15:36:29
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

signed main()
{
    IOS;
    int n;
    cin >> n;

    struct sa
    {
        string name;
        int age, g;
    };

    vector<sa> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].name >> a[i].age >> a[i].g;
    }

    sort(a.begin(), a.end(), [&](sa a, sa b) {
        if (a.g != b.g)
            return a.g < b.g;
        else if (a.name != b.name)
            return a.name < b.name;
        else
            return a.age < b.age;
    });

    for (auto [name, age, g] : a)
        printf("%s %lld %lld\n", name.c_str(), age, g);
    return 0;
}