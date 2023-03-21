'''
Author: NEFU AB-IN
Date: 2023-03-19 15:17:56
FilePath: \Acwing\4074\4074.py
LastEditTime: 2023-03-19 15:32:18
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(410)
INF = int(2e9)
g1 = [[INF] * N for _ in range(N)]
g2 = [[INF] * N for _ in range(N)]


def floyd(g):
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])
    return g[1][n]


n, m = read()
for i in range(m):
    u, v = read()
    g1[u][v] = g1[v][u] = 1

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            g1[i][j] = g2[i][j] = 0
        if g1[i][j] == INF:
            g2[i][j] = g2[j][i] = 1

ans = max(floyd(g1), floyd(g2))

print(-1 if ans == INF else ans)
