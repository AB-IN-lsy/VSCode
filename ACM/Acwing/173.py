'''
Author: NEFU AB-IN
Date: 2022-04-12 16:29:20
FilePath: \ACM\Acwing\173.py
LastEditTime: 2022-04-12 16:34:34
'''
N = 1010
from collections import deque

g = []
dist = [[0] * N for _ in range(N)]
st = [[0] * N for _ in range(N)]

n, m = map(int, input().split())
for i in range(n):
    g.append(list(map(int, input())))

q = deque()

for i in range(n):
    for j in range(m):
        if g[i][j] == 1:
            st[i][j] = 1
            q.appendleft([i, j])

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

while q:
    x, y = q.pop()
    for i in range(4):
        a = x + dx[i]
        b = y + dy[i]
        if a >= 0 and a < n and b >= 0 and b < m and st[a][b] == 0:
            dist[a][b] = dist[x][y] + 1
            st[a][b] = 1
            q.appendleft([a, b])

for i in range(n):
    for j in range(m):
        print(dist[i][j], end=" ")
    print()