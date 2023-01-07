/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-06 18:00:41
 * @FilePath: \GPLT\A1023\A1023.cpp
 * @LastEditTime: 2023-01-06 18:14:01
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
#define DEBUG(X) cout << #X << ": " << X << endl
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

// #undef int

vector<int> add(vector<int> A, vector<int> B)
{
    vector<int> C;
    int t = 0;

    for (int i = 0; i < SZ(A); i++)
    {
        int s = A[i] + B[i] + t;
        C.push_back(s % 10);
        t = s / 10;
    }

    if (t)
        C.push_back(t);
    return C;
}

vector<int> mul(vector<int> A, int B)
{
    vector<int> C;
    int t = 0;

    for (int i = 0; i < SZ(A); i++)
    {
        int s = A[i] * B + t;
        C.push_back(s % 10);
        t = s / 10;
    }

    if (t)
        C.push_back(t);
    return C;
}

signed main()
{
    IOS;
    string s;
    cin >> s;

    vector<int> a;
    for (int i = SZ(s) - 1; i >= 0; --i)
        a.push_back(s[i] - '0');

    vector<int> b = mul(a, 2);
    vector<int> c = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << (a == b ? "Yes" : "No") << '\n';
    for (int i = SZ(c) - 1; i >= 0; --i)
        cout << c[i];
    return 0;
}