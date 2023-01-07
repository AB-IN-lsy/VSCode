/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 17:43:29
 * @FilePath: \GPLT\A1028\A1028.cpp
 * @LastEditTime: 2023-01-07 17:47:38
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

// #undef N
// const int N = 1e5 + 10;

// #undef int

struct sa
{
    string id, name;
    int grade;
};

signed main()
{
    IOS;
    vector<sa> a;

    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
    {
        string id, name;
        int grade;
        cin >> id >> name >> grade;
        a.push_back({id, name, grade});
    }
    sort(a.begin(), a.end(), [&](const sa a, const sa b) {
        if (a.name != b.name && c == 2)
            return a.name < b.name;
        if (a.grade != b.grade && c == 3)
            return a.grade < b.grade;
        return a.id < b.id;
    });

    for (auto &[id, name, grade] : a)
    {
        cout << id << " " << name << " " << grade << '\n';
    }

    return 0;
}