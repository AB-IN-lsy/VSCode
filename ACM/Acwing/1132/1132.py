'''
Author: NEFU AB-IN
Date: 2022-04-16 11:41:05
FilePath: \ACM\Acwing\1132.py
LastEditTime: 2022-04-16 11:41:06
'''
from collections import deque
from copy import deepcopy

N = 1010
INF = int(1e10)
g = [[] for _ in range(N)]
dist, st = [INF] * N, [0] * N


def spfa(u):
    q = deque()
    q.appendleft(u)
    st[u] = 1
    dist[u] = 0
    while q:
        u = q.pop()
        st[u] = 0
        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                if st[v] == 0:
                    st[v] = 1
                    q.appendleft(v)


n, m, s = map(int, input().split())

record = []
for i in range(m):
    u, v, w = map(int, input().split())
    record.append([u, v, w])
    g[u].append([v, w])
spfa(s)
dist1 = deepcopy(dist)

g = [[] for _ in range(N)]
dist, st = [INF] * N, [0] * N
for i in range(m):
    v, u, w = record[i]
    g[u].append([v, w])
spfa(s)
ans = 0
for i in range(1, n + 1):
    ans = max(ans, dist[i] + dist1[i])

print(ans)
