'''
Author: NEFU AB-IN
Date: 2022-04-03 17:55:14
FilePath: \ACM\Acwing\1220.py
LastEditTime: 2022-04-03 19:09:18
'''
import sys

sys.setrecursionlimit(int(2e9))

N = int(1e5 + 10)
INF = int(1e18)
g = [[] for _ in range(N)]
dist = [0] * N
ans = 0


def dfs(fa, u):
    global ans
    dist[u] = a[u]
    for v in g[u]:
        if v == fa:
            continue
        dfs(u, v)
        dist[u] += max(0, dist[v])
    ans = max(ans, dist[u])


n = int(input())
a = list(map(int, input().split()))
a = [0, *a]

for i in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

dfs(-1, 1)
print(ans)