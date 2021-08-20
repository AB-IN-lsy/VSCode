/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-16 13:08:25
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.16\f.cpp
 * @LastEditTime: 2021-08-20 02:52:24
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
string parentheses;  //括号序列
int partp = 0;       //遍历到括号序列的位置
int book[maxn + 10]; //记录颜色数量
struct colorNode
{
    int type;
    int num;
}; //颜色结点，包括种类和数量
bool operator<(const colorNode x, const colorNode y)
{ //优先队列重载小于号
    return x.num < y.num;
}
priority_queue<colorNode> colorque;
struct treeNode
{
    vector<int> son;
    int color;
} tree[maxn + 10]; //树结点，包括儿子和颜色
int nowid = 0;     //当前遍历到的树结点
void dfs(int father)
{ //子树根节点
    while (parentheses[partp] == '(')
    { //如果是左括号，说明要继续往下搜索，进入子树
        partp++;
        nowid++; //结点顺次编号
        tree[father].son.push_back(nowid);
        dfs(nowid);
    }
    partp++; //右括号说明要返回上一层
    return;
}
bool bfs()
{
    queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        for (int i = 0; i < que.size(); i++)
        {
            int now = que.front();
            que.pop();
            vector<colorNode> coltemp;
            for (int j = 0; j < tree[now].son.size(); j++)
            {
                int Son = tree[now].son[j];
                que.push(Son);
                if (colorque.empty())
                    return 0;
                colorNode col = colorque.top();
                colorque.pop();
                tree[Son].color = col.type;
                col.num--;
                if (col.num != 0)
                {
                    coltemp.push_back(col);
                }
            }
            for (int j = 0; j < coltemp.size(); j++)
            {
                colorque.push(coltemp[j]);
            }
        }
    }
    return 1;
}
int main()
{
    int N;
    cin >> N;
    parentheses += '(';
    cin >> parentheses;
    parentheses += ')'; //补全树根
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        book[x]++;
    }
    for (int Type = 0; Type <= maxn; Type++)
    {
        if (book[Type] != 0)
            colorque.push({Type, book[Type]});
    }
    dfs(0);
    if (bfs() == 0)
    {
        printf("NO\n");
        return 0;
    }
    else
    {
        printf("YES\n");
    }
    for (int i = 1; i <= nowid; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", tree[i].color);
    }
    return 0;
}
