'''
Author: NEFU AB-IN
Date: 2022-04-16 11:08:47
FilePath: \ACM\Acwing\4241.py
LastEditTime: 2022-04-16 11:08:48
'''
from collections import deque

N = 1010
INF = int(1e9)
g = [[0] * N for _ in range(N)]
dist, st = [0] * N, [0] * N


def spfa(u):
    q = deque()
    q.appendleft(u)
    st[u] = 1
    dist[u] = INF
    while q:
        u = q.pop()
        st[u] = 0
        for v in range(1, n + 1):
            if dist[v] < min(dist[u], g[u][v]):
                dist[v] = min(dist[u], g[u][v])
                if st[v] == 0:
                    st[v] = 1
                    q.appendleft(v)
    return dist[n]


for _ in range(1, int(input()) + 1):
    dist, st = [0] * N, [0] * N
    g = [[0] * N for _ in range(N)]
    n, m = map(int, input().split())
    for i in range(m):
        u, v, w = map(int, input().split())
        g[u][v] = w
        g[v][u] = w
    print(f"Scenario #{_}:")
    print(spfa(1))
    print()
