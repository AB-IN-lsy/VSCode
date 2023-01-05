/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-05 12:45:02
 * @FilePath: \GPLT\A1019\A1019.cpp
 * @LastEditTime: 2023-01-05 12:55:00
 */
#include <bits/stdc++.h>
#define int long long
#define SZ(X) ((int)(X).size())

using namespace std;

signed main()
{

    int n, b;
    cin >> n >> b;

    vector<string> s;
    if (!n)
    {
        cout << "Yes\n0";
        return 0;
    }
    while (n)
    {
        s.push_back(to_string(n % b));
        n /= b;
    }
    int flag = 1, len = SZ(s);
    for (int i = 0; i < len / 2; ++i)
    {
        if (s[i] != s[len - 1 - i])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        puts("Yes");
    else
        puts("No");

    for (int i = SZ(s) - 1; i >= 0; --i)
        cout << s[i] << " "[i == 0];
    return 0;
}