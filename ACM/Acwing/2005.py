'''
Author: NEFU AB-IN
Date: 2022-02-11 14:28:34
FilePath: \ACM\Acwing\2005.py
LastEditTime: 2022-02-11 16:05:22
'''
import sys

sys.setrecursionlimit(10000000)

g = []
vis = [[0 for _ in range(5)] for _ in range(5)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

res = 0


def dfs(x, y, lnum, rnum, op):
    global res
    vis[x][y] = 1
    if op == '(':
        lnum += 1
    else:
        rnum += 1
    if lnum == rnum:
        res = max(res, lnum + rnum)
        vis[x][y] = 0
        return
    for i in range(4):
        a = x + dx[i]
        b = y + dy[i]
        if a >= 0 and a < n and b >= 0 and b < n and vis[a][b] == 0:
            if op == '(' or (op == ')' and g[a][b] == ')'):
                dfs(a, b, lnum, rnum, g[a][b])
    vis[x][y] = 0


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        g.append(input())
    if g[0][0] == '(':
        dfs(0, 0, 0, 0, g[0][0])
    print(res)