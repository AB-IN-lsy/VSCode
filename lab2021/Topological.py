'''
Description: Topological
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-18 08:56:10
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-18 09:29:03
'''
from queue import Queue

N = 20
h = [-1 for _ in range(N)]  # head数组
ne = [0 for _ in range(N)]  # Next数组
e = [0 for _ in range(N)]   # edge.v 数组  
w = [0 for _ in range(N)]   # weight 数组
color = [0 for _ in range(N)] #white = 0, grey = 1, black = 2
idx = 0

def add(a, b, ww):
    global idx
    e[idx] = b
    ne[idx] = h[a]
    w[idx] = ww
    h[a] = idx
    idx += 1

# start with 0
n, m = map(int, input().split())
indegree = [0 for _ in range(n)]
order = []
for _ in range(m):
    u, v = map(int, input().split())
    add(u, v, 1)
    indegree[v] += 1
q = Queue()
for _ in range(n):
    if indegree[_] == 0:
        q.put(_)
cnt = 0
while q.qsize():
    u = q.get()
    order.append(u)
    cnt += 1
    i = h[u]
    while i != -1:
        v = e[i]
        indegree[v] -= 1
        if indegree[v] == 0:
            q.put(v)
        i = ne[i]
if cnt != n:
    print("Not exist Topological")
else:
    print(*order)

