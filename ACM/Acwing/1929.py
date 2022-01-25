'''
Author: NEFU AB-IN
Date: 2022-01-20 00:31:57
FilePath: \ACM\Acwing\1929.py
LastEditTime: 2022-01-20 00:55:18
'''
g = []

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
#上右下左
'''
    0
  3< > 1
    2
'''


def dfs(x, y, op):
    cnt = 0
    while x >= 0 and x < n and y >= 0 and y < m:
        op = (op ^ 1) if g[x][y] == '/' else (op ^ 3)
        x += dx[op]
        y += dy[op]
        cnt += 1
    return cnt


if __name__ == "__main__":
    n, m = map(int, input().split())
    for _ in range(n):
        s = input()
        g.append(s)
    res = 0
    # 枚举所有边界点
    # 两个边界列
    for i in range(n):
        res = max(res, dfs(i, 0, 1))  #1 代表从左边往右进的
        res = max(res, dfs(i, m - 1, 3))  #3 代表从右边往左进的
    # 两个边界行
    for i in range(m):
        res = max(res, dfs(0, i, 2))  #2 代表从上面往下进的
        res = max(res, dfs(n - 1, i, 0))  #0 代表从下面往上进的
    print(res)