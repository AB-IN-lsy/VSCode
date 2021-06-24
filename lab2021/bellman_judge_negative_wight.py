'''
Description: Bellman-Ford
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-23 19:41:55
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-24 18:18:19
'''
import copy
class edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w
inf = 0x3f3f3f3f
# n vertexes, m edges
n, m = map(int, input().split())
edges = list()
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append(edge(u, v, w))

# vertex range [1, n]
dist = [inf for _ in range(n + 1)]
dist[1] = 0
cnt = [0 for _ in range(n + 1)]

for _ in range(n):
    back = copy.deepcopy(dist)
    for i in range(m):
        u = edges[i].u
        v = edges[i].v
        w = edges[i].w
        if dist[v] > dist[u] + w:
            dist[v] = dist[u] + w
            cnt[v] = cnt[u] + 1
            if cnt[v] >= n:
                print("exist cycle of negative weights")
                exit(0)

print("NOT exist cycle of negative weights")
'''
5 5
1 2 1
2 3 -10
3 4 2
4 2 3
4 5 1

exist cycle of negative weights
'''
