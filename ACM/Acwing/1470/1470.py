'''
Author: NEFU AB-IN
Date: 2022-03-30 21:11:39
FilePath: \ACM\Acwing\1470.py
LastEditTime: 2022-03-30 21:11:40
'''
from collections import deque

g = []
st = [[0] * 10 for _ in range(10)]
dir = [[-1, 0], [0, 1], [1, 0], [0, -1]]
for i in range(10):
    g.append(list(input()))

for i in range(10):
    for j in range(10):
        if g[i][j] == 'B':
            sx, sy = i, j
        if g[i][j] == 'L':
            ex, ey = i, j

q = deque()
st[sx][sy] = 1
q.appendleft([sx, sy, 0])
while q:
    x1, y1, cnt = q.pop()
    if x1 == ex and y1 == ey:
        print(cnt - 1)
        break
    for i in range(4):
        x = x1 + dir[i][0]
        y = y1 + dir[i][1]
        if x >= 0 and x < 10 and y >= 0 and y < 10 and (
                g[x][y] == '.' or g[x][y] == 'L') and st[x][y] == 0:
            q.appendleft([x, y, cnt + 1])
            st[x][y] = 1