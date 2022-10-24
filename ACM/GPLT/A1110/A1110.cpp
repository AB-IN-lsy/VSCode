/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-13 15:56:41
 * @FilePath: \GPLT\A1110\A1110.cpp
 * @LastEditTime: 2022-09-13 16:16:45
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> l(n, -1), r(n, -1), st(n);
    for (int i = 0; i < n; ++i)
    {
        string p, q;
        cin >> p >> q;
        if (p != "-")
            l[i] = stoi(p), st[stoi(p)] = 1;
        if (q != "-")
            r[i] = stoi(q), st[stoi(q)] = 1;
    }

    int root;
    for (int i = 0; i < n; ++i)
    {
        if (!st[i])
        {
            root = i;
            break;
        }
    }

    // cout << root << '\n';
    queue<int> ans;
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        ans.push(t);
        // cout << t << '\n';
        if (~t)
        {
            q.push(l[t]);
            q.push(r[t]);
        }
    }

    int res;
    while (ans.size())
    {
        if (ans.front() != -1)
        {
            res = ans.front();
            ans.pop();
        }
        else
            break;
    }

    int flag = 1;
    while (ans.size())
    {
        if (~ans.front())
        {
            flag = 0;
            break;
        }
        ans.pop();
    }

    if (flag)
        cout << "YES " << res;
    else
        cout << "NO " << root;
}