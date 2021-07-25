'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-24 09:31:22
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-24 09:33:47
'''
import copy
class edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w
inf = 0x3f3f3f3f
# n vertexes, m edges, k lines input
n, m = map(int, input().split())
edges = list()
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append(edge(u, v, w))

# vertex range [1, n]
dist = [inf for _ in range(n + 1)]
dist[1] = 0

for _ in range(n):
    for i in range(m):
        u = edges[i].u
        v = edges[i].v
        w = edges[i].w
        if dist[v] > dist[u] + w:
            dist[v] = min(dist[v], dist[u] + w)
    
if dist[n] > inf / 2:
    print("impossible")
else:
    print(dist[n])
'''
input
3 3
1 2 1
2 3 1
1 3 3

output
2
'''