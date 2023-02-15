'''
Author: NEFU AB-IN
Date: 2022-04-16 16:28:28
FilePath: \ACM\Acwing\4243.py
LastEditTime: 2022-04-16 16:31:22
'''
from collections import deque

N = 150
INF = int(1e9)
g = [[] for _ in range(N)]
dist, st = [INF] * N, [0] * N


def spfa():
    q = deque()
    q.appendleft(1)
    st[1] = 1
    dist[1] = 0
    while q:
        u = q.pop()
        st[u] = 0

        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                if st[v] == 0:
                    st[v] = 1
                    q.appendleft(v)


n = int(input())
for i in range(2, n + 1):
    lst = [0, *input().split()]
    for j in range(1, i):
        if lst[j] != 'x':
            g[i].append([j, int(lst[j])])
            g[j].append([i, int(lst[j])])
spfa()
ans = -INF
for i in range(2, n + 1):
    if dist[i] != INF:
        ans = max(ans, dist[i])
print(ans)
