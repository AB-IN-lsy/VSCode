'''
Author: NEFU AB-IN
Date: 2023-03-19 15:48:41
FilePath: \Acwing\1125\1125.py
LastEditTime: 2023-03-19 16:27:41
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations
from math import sqrt

N = int(160)
INF = int(2e9)
pos = [[] for _ in range(N)]
g = [0]
dist = [[INF] * N for _ in range(N)]
mx = [0] * N


def cale(i, j):
    x1, y1 = pos[i]
    x2, y2 = pos[j]
    return sqrt(abs(x1 - x2)**2 + abs(y1 - y2)**2)


def floyd():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


n = int(input())
for i in range(1, n + 1):
    x, y = read()
    pos[i] = [x, y]

for i in range(n):
    g.append('0' + input())

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            dist[i][j] = 0
        if g[i][j] == '1':
            dist[i][j] = dist[j][i] = cale(i, j)

floyd()

ans1, ans2 = 0, INF
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if dist[i][j] != INF:
            mx[i] = max(mx[i], dist[i][j])
    ans1 = max(ans1, mx[i])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if dist[i][j] == INF:
            ans2 = min(ans2, mx[i] + cale(i, j) + mx[j])

print(f"{max(ans1, ans2):.6f}")
