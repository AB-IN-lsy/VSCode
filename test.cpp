/*
 * @Author: NEFU AB-IN
 * @Date: 2021-07-16 18:21:31
 * @FilePath: \Vscode\test.cpp
 * @LastEditTime: 2021-09-17 21:40:10
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

signed main()
{
    IOS;
    string a = "abcda";
    cout << a.find("f") << endl;
    cout << a.find("a", 0) << endl;
    cout << a.find("a", 1) << endl;
    return 0;
}