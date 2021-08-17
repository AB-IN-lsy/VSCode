/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-13 13:37:53
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-08-13 13:37:53
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define PI acos(-1.0)
#define E 1e-9
#define INF 0x3f3f3f3f
#define LL long long
const int N = 10000 + 5;
using namespace std;

int n, m;         //x、y中结点个数，下标从0开始
bool vis[N];      //vis[i]表示是否在交替路中
int link[N];      //存储连接点
vector<int> G[N]; //存边
bool dfs(int x)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        int y = G[x][i];
        if (!vis[y])
        {                  //不在交替路中
            vis[y] = true; //放入交替路
            if (link[y] == -1 || dfs(link[y]))
            {                //如果是未匹配点，说明交替路是增广路
                link[y] = x; //交换路径
                return true; //返回成功
            }
        }
    }
    return false; //不存在增广路，返回失败
}
int hungarian()
{
    int ans = 0; 
    for (int i = 0; i < n; i++)
    { 
        memset(vis, false, sizeof(vis));
        if (dfs(i)) 
            ans++;
    }
    return ans;
}
int main()
{
    while (scanf("%d", &n) != EOF && (n))
    {
        memset(link, -1, sizeof(link));
        for (int i = 0; i < n; i++)
            G[i].clear();

        for (int i = 0; i < n; i++)
        {
            int x, num;
            scanf("%d: (%d)", &x, &num);
            while (num--)
            {
                int y;
                scanf("%d", &y);
                G[x].push_back(y);
            }
        }

        printf("%d\n", n - hungarian() / 2); 
    }
    return 0;
}