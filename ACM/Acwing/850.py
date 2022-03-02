'''
Author: NEFU AB-IN
Date: 2022-03-02 22:48:43
FilePath: \ACM\Acwing\850.py
LastEditTime: 2022-03-02 23:13:33
'''
import heapq

N = int(2e5 + 10)
INF = int(2e9)
st, dist = [0] * N, [INF] * N
g = [[] for _ in range(N)]


def dij(s):
    dist[s] = 0
    q = []
    heapq.heappush(q, [0, s])
    while q:
        t = heapq.heappop(q)
        distance, u = t
        if st[u]:
            continue
        st[u] = 1
        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(q, [dist[v], v])
    if dist[n] == INF:
        return -1
    return dist[n]


n, m = map(int, input().split())
for i in range(m):
    x, y, z = map(int, input().split())
    g[x].append([y, z])

print(dij(1))