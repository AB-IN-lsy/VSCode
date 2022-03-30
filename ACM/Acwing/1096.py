'''
Author: NEFU AB-IN
Date: 2022-03-29 16:41:44
FilePath: \ACM\Acwing\1096.py
LastEditTime: 2022-03-29 16:54:14
'''
from collections import deque

N = 110
while True:
    st = [[[0] * N for _ in range(N)] for _ in range(N)]
    g = [[] for _ in range(N)]
    l, n, m = map(int, input().split())
    if l + n + m == 0:
        break
    for k in range(l):
        for i in range(n):
            g[k].append(list(input()))
        t = input()

    for k in range(l):
        for i in range(n):
            for j in range(m):
                if g[k][i][j] == 'S':
                    sz, sx, sy = k, i, j
                if g[k][i][j] == 'E':
                    ez, ex, ey = k, i, j

    dir = [[0, 1, 0], [0, -1, 0], [0, 0, 1], [0, 0, -1], [1, 0, 0], [-1, 0, 0]]
    q = deque()
    q.appendleft([sz, sx, sy, 0])
    st[sz][sx][sy] = 1
    while q:
        z1, x1, y1, cnt = q.pop()
        if z1 == ez and x1 == ex and y1 == ey:
            print(f"Escaped in {cnt} minute(s).")
            break
        for i in range(6):
            z = z1 + dir[i][0]
            x = x1 + dir[i][1]
            y = y1 + dir[i][2]
            if x >= 0 and x < n and y >= 0 and y < m and z >= 0 and z < l and (
                    g[z][x][y] == 'E'
                    or g[z][x][y] == '.') and st[z][x][y] == 0:
                st[z][x][y] = 1
                q.appendleft([z, x, y, cnt + 1])
    if st[ez][ex][ey] == 0:
        print("Trapped!")