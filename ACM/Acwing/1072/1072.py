import sys

sys.setrecursionlimit(int(2e9))
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

N = int(1e3 + 10)
INF = int(2e9)
'''
Author: NEFU AB-IN
Date: 2022-04-05 10:57:05
FilePath: \Acwing\1072\1072.py
LastEditTime: 2023-03-25 23:14:38
'''
import sys

sys.setrecursionlimit(int(2e9))

N = int(1e4 + 10)
g = [[] for _ in range(N)]
dist1, dist2 = [0] * N, [0] * N
ans = 0


def dfs(fa, u):
    global ans
    for v, w in g[u]:
        if v == fa:
            continue
        dfs(u, v)
        dis = dist1[v] + w
        if dis >= dist1[u]:  #这里大于等于 或 大于都可以
            dist2[u] = dist1[u]
            dist1[u] = dis
        elif dis >= dist2[u]:
            dist2[u] = dis
    ans = max(ans, dist1[u] + dist2[u])


n = int(input())
for i in range(n - 1):
    u, v, w = read()
    g[u].append([v, w])
    g[v].append([u, w])

dfs(-1, 1)
print(ans)
