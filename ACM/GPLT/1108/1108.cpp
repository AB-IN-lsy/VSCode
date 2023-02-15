/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-04 14:21:10
 * @FilePath: \ACM\GPLT\1108.cpp
 * @LastEditTime: 2022-06-04 14:21:10
 */
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())

using namespace std;

map<char, int> d;
int main()
{
    string s;
    cin >> s;
    for (auto i : s)
        d[i]++;
    string t = "String";

    while (1)
    {
        int flag = 0;
        for (int i = 0; i < SZ(t); ++i)
        {
            if (d[t[i]])
            {
                d[t[i]]--;
                cout << t[i];
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    return 0;
}