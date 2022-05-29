/*
 * @Author: NEFU AB-IN
 * @Date: 2022-05-22 22:47:23
 * @FilePath: \ACM\Acwing\1927.cpp
 * @LastEditTime: 2022-05-22 23:33:58
 */
#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int son[N][26], cnt[N], idx, num;

unordered_map<string, int> d;

void insert(string str) // 插入字符串
{
    int p = 0;
    for (int i = 0; i < SZ(str); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str) // 查询前缀是否存在
{
    int p = 0;
    for (int i = 0; i < SZ(str); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return p;
}

int flag, res;
void dfs(int p, string pre)
{
    if (flag)
        return;
    if (cnt[p])
    {
        res += 1;
        if (res == num)
        {
            flag = 1;
            cout << d[pre] << '\n';
            return;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (son[p][i])
        {
            string ss = pre + (char)(97 + i);
            dfs(son[p][i], ss);
        }
    }
}

signed main()
{
    IOS;
    int w, n;
    cin >> w >> n;
    for (int i = 1; i <= w; ++i)
    {
        string s;
        cin >> s;
        insert(s);
        d[s] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        string pre;
        cin >> num >> pre;

        int p = query(pre);
        if (!p)
        {
            cout << "-1\n";
            continue;
        }
        dfs(p, pre);
        if (!flag)
            cout << "-1\n";
        // 回归状态
        flag = 0;
        res = 0;
    }
    return 0;
}