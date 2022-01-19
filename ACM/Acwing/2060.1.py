'''
Author: NEFU AB-IN
Date: 2022-01-17 22:29:48
FilePath: \ACM\Acwing\2060.1.py
LastEditTime: 2022-01-17 23:07:00
'''

#BFS

from collections import deque


class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y


n, m = map(int, input().split())

g = []
vis = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
point = [[] for _ in range(2)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
# 左上右下
q = deque()


def bfs(x, y, p):
    vis[x][y] = 0
    p.append(Point(x, y))
    q.appendleft(Point(x, y))
    while q.__len__():
        top = q.pop()
        x = top.x
        y = top.y
        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if xx >= 0 and yy >= 0 and xx < n and yy < m and vis[xx][yy] == 1:
                q.appendleft(Point(xx, yy))
                p.append(Point(xx, yy))
                vis[xx][yy] = 0


if __name__ == "__main__":
    for i in range(n):
        s = input()
        g.append(list(s))
        for j in range(len(s)):
            vis[i][j] = 1 if g[i][j] == 'X' else 0
    k = 0
    for i in range(n):
        for j in range(m):
            if vis[i][j] == 1:
                bfs(i, j, point[k])
                k += 1
    res = int(2e9)
    for i in point[0]:
        for j in point[1]:
            res = min(res, abs(i.x - j.x) + abs(i.y - j.y) - 1)
    print(res)

# 2,6
# 4,8