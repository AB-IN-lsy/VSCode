'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-23 19:41:55
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-24 09:33:58
'''
import copy
class edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w
inf = 0x3f3f3f3f
# n vertexes, m edges, k lines input
n, m, k = map(int, input().split())
edges = list()
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append(edge(u, v, w))

# vertex range [1, n]
dist = [inf for _ in range(n + 1)]
back = list()
dist[1] = 0

for _ in range(k):#k次循环
    back = copy.deepcopy(dist)
    for i in range(m):
        u = edges[i].u
        v = edges[i].v
        w = edges[i].w
        if dist[v] > dist[u] + w:
            dist[v] = min(dist[v], back[u] + w)
        #使用backup:避免给u更新后立马更新v, 这样好控制边数，一次循环每个点最多多一条边

if dist[n] > inf / 2:
    print("impossible")
else:
    print(dist[n])
'''
3 3 1
1 2 1
2 3 1
1 3 3

3
'''