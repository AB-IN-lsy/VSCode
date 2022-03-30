/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-25 10:13:38
 * @FilePath: \ACM\test.cpp
 * @LastEditTime: 2022-03-28 21:09:43
 */
#include <bits/stdc++.h>
using namespace std;
string a[100005];
int main()
{
    int n, k;
    long long sum = 0;
    cin >> n >> k;
    map<string, int> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum = sum + m[a[i]];
        m[a[i]]++;
        if (i > k + 1)
            m[a[i - k - 1]]--;
    }
    cout << sum << '\n';
}