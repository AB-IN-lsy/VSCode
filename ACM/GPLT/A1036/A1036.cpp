/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-08 18:55:28
 * @FilePath: \GPLT\A1036\A1036.cpp
 * @LastEditTime: 2023-01-08 18:55:45
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
struct sa
{
    string id, word;
};

signed main()
{
    int n;
    cin >> n;
    int grade_F = -1, grade_M = 101, ans = 0;
    string name_F, id_F, name_M, id_M;
    for (int i = 0; i < n; ++i)
    {
        string name, sex, id;
        int grade;
        cin >> name >> sex >> id >> grade;
        if (sex == "M" && grade_M > grade)
        {
            name_M = name;
            grade_M = grade;
            id_M = id;
        }
        if (sex == "F" && grade_F < grade)
        {
            name_F = name;
            grade_F = grade;
            id_F = id;
        }
    }
    if (grade_F == -1)
    {
        cout << "Absent\n";
        cout << name_M << " " << id_M << '\n';
        cout << "NA\n";
    }
    else if (grade_M == 101)
    {
        cout << name_F << " " << id_F << '\n';
        cout << "Absent\n";
        cout << "NA\n";
    }
    else
    {
        cout << name_F << " " << id_F << '\n';
        cout << name_M << " " << id_M << '\n';
        cout << grade_F - grade_M << '\n';
    }
    return 0;
}