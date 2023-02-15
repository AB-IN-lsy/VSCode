'''
Author: NEFU AB-IN
Date: 2022-03-29 21:06:30
FilePath: \ACM\Acwing\1207.py
LastEditTime: 2022-03-29 21:06:31
'''
import sys

sys.setrecursionlimit(int(2e9))

N = int(1e5 + 10)
g = [[] for _ in range(N)]
dist = [0] * N


def dfs(u, fa, dis):
    dist[u] = dis
    for v, w in g[u]:
        if v == fa: continue
        dfs(v, u, dis + w)


n = int(input())
for i in range(n - 1):
    u, v, w = map(int, input().split())
    g[u].append([v, w])
    g[v].append([u, w])

dfs(1, -1, 0)
u = 1
for i in range(1, n + 1):
    if dist[i] > dist[u]:
        u = i

dfs(u, -1, 0)
for i in range(1, n + 1):
    if dist[i] > dist[u]:
        u = i

w = dist[u]
print(10 * w + w * (w + 1) // 2)