'''
Author: NEFU AB-IN
Date: 2022-03-04 14:01:18
FilePath: \ACM\Acwing\853.py
LastEditTime: 2022-03-04 15:39:01
'''
from copy import deepcopy

N = 550
INF = int(2e9)


class Edge():
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


dist = [INF] * N


def bellman_ford():
    dist[1] = 0
    for i in range(k):
        backup = deepcopy(dist)
        for j in range(m):
            u, v, w = lst[j].u, lst[j].v, lst[j].w
            dist[v] = min(dist[v], backup[u] + w)
    if dist[n] > INF // 2:
        return INF
    return dist[n]


lst = []
n, m, k = map(int, input().split())
for i in range(m):
    u, v, w = map(int, input().split())
    lst.append(Edge(u, v, w))

res = bellman_ford()
if res == INF:
    print("impossible")
else:
    print(res)
