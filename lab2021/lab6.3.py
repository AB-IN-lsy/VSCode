'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-11 09:10:18
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 10:56:54
'''
from queue import PriorityQueue


def shortest_path(adj_list, s):
    # 默认边权为1，故只存点
    n = len(adj_list)
    color = [0 for _ in range(n)] 
    d = [float('inf') for _ in range(n)]
    d[s] = 0
    q = PriorityQueue()
    q.put((0, s))
    while q.qsize():
        ns = q.get()
        x = ns[1]
        if color[x] == 1:
            continue
        color[x] = 1
        for v in adj_list[x]:
            if d[v] > d[x] + 1:
                d[v] = d[x] + 1
                q.put((d[v], v))
    return d[: n]

adj_list = [[1, 2], [0, 2, 3], [0, 1], [1]]
d = shortest_path(adj_list, 3)
print(d)

    