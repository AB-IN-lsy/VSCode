'''
Author: NEFU AB-IN
Date: 2022-04-19 11:16:47
FilePath: \ACM\GPLT\L2-001.PY
LastEditTime: 2022-04-19 15:20:26
'''
from heapq import heappush, heappop

N = int(1e3 + 10)
INF = int(2e9)
st, dist, num, ww, pre = [0] * N, [INF] * N, [0] * N, [0] * N, [-1] * N
g = [[] for _ in range(N)]


def dij(s):
    q = []
    heappush(q, [0, s])
    dist[s] = 0
    ww[s] = people[s]
    num[s] = 1
    while q:
        dis, u = heappop(q)
        if st[u]:
            continue
        st[u] = 1
        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                num[v] = num[u]
                ww[v] = ww[u] + people[v]
                pre[v] = u
                heappush(q, [dist[v], v])
            elif dist[v] == dist[u] + w:
                num[v] += num[u]
                if ww[v] < ww[u] + people[v]:
                    ww[v] = ww[u] + people[v]
                    pre[v] = u


n, m, s, d = map(int, input().split())
people = list(map(int, input().split()))
for i in range(m):
    u, v, w = map(int, input().split())
    g[u].append([v, w])
    g[v].append([u, w])

dij(s)
print(num[d], ww[d])

path = []
while d != -1:
    path.append(d)
    d = pre[d]
path = path[::-1]
print(" ".join(map(str, path)))