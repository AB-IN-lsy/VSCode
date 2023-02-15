'''
Author: NEFU AB-IN
Date: 2022-03-28 21:23:05
FilePath: \ACM\Acwing\1101.py
LastEditTime: 2022-03-28 21:23:06
'''
from collections import deque
for _ in range(int(input())):
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    n, m = map(int, input().split())
    st = [[0] * m for _ in range(n)]
    g = []
    for i in range(n):
        g.append(list(input()))
    for i in range(n):
        for j in range(m):
            if g[i][j] == 'S':
                sx, sy = i, j
            if g[i][j] == 'E':
                ex, ey = i, j
    q = deque()
    q.appendleft([sx, sy, 0])
    st[sx][sy] = 1
    while q:
        x, y, cnt = q.pop()
        if x == ex and y == ey:
            print(cnt)
            break
        for i in range(4):
            x1 = x + dx[i]
            y1 = y + dy[i]
            if x1 >= 0 and x1 < n and y1 >= 0 and y1 < m and (
                    g[x1][y1] == '.' or g[x1][y1] == 'E') and st[x1][y1] == 0:
                q.appendleft([x1, y1, cnt + 1])
                st[x1][y1] = 1
    if st[ex][ey] == 0:
        print("oop!")