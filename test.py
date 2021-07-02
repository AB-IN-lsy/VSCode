'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-01-28 23:02:48
LastEditors: NEFU AB_IN
LastEditTime: 2021-07-02 18:44:19
'''
from queue import PriorityQueue

N = 20
h = [-1 for _ in range(N)]
ne = [0 for _ in range(N)]
e = [0 for _ in range(N)]
w = [0 for _ in range(N)]
# white = 0, grey = 1, black = 2
idx = 0

def add(a, b, ww):
    global idx
    e[idx] = b
    ne[idx] = h[a]
    w[idx] = ww
    h[a] = idx
    idx += 1

def shortest_path(adj_list, s):
    global h, ne, idx
    color = [0 for _ in range(N)] 
    d = [float('inf') for _ in range(N)]
    for i in range(len(adj_list)):
        for j in adj_list[i]:
            add(i, j, adj_list[i][j])
    d[s] = 0
    q = PriorityQueue()
    q.put((0, s))
    while q.qsize():
        ns = q.get()
        x = ns[1]
        if color[x] == 1:
            continue
        color[x] = 1
        i = h[x]
        while i != -1:
            j = e[i]
            if d[j] > d[x] + w[i]:
                d[j] = d[x] + w[i]
                q.put((d[j], j))
            i = ne[i]
    h = [-1 for _ in range(N)]
    ne = [0 for _ in range(N)]
    idx = 0
    return d[:len(adj_list)]