/*
 * @Author: NEFU AB-IN
 * @Date: 2022-05-12 20:04:45
 * @Last Modified by:   NEFU AB-IN
 * @Last Modified time: 2022-05-12 20:04:45
 */
#include <bits/stdc++.h>
#define SZ(X) ((int)X.size())

using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int _ = 1; _ <= k; ++_)
    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        stack<int> s;
        int cnt = 1;  // 需要push进去的元素
        int id = 0;   // 判断序列的指针
        int flag = 1; // 是否成立
        while (cnt < n + 1)
        {
            s.push(cnt++);
            if (SZ(s) > m)
            {
                flag = 0;
                break;
            }
            while (SZ(s) && s.top() == a[id])
            {
                id++;
                s.pop();
            }
        }
        if (flag && !SZ(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}