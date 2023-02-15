/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-19 14:31:38
 * @FilePath: \ACM\Acwing\3283.cpp
 * @LastEditTime: 2022-03-19 14:31:39
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int ans[5];
vector<PII> v;
unordered_map<int, unordered_map<int, int>> g;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < n; i++)
    {
        int x = v[i].first, y = v[i].second;
        if (g[x][y] && g[x + 1][y] && g[x][y + 1] && g[x - 1][y] && g[x][y - 1])
        {
            int cnt = g[x - 1][y + 1] + g[x - 1][y - 1] + g[x + 1][y - 1] + g[x + 1][y + 1];
            ans[cnt]++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", ans[i]);
    }
}