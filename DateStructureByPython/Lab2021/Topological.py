'''
Description: Topological
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-18 08:56:10
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 10:47:20
'''
from queue import PriorityQueue
# 优化，即顺序按照字典序输出

# start with 0
n, m = map(int, input().split())
indegree = [0 for _ in range(n)]
lst = [[] for _ in range(n)] # Adjacency List
order = []

for _ in range(m):
    u, v = map(int, input().split())
    lst[u].append(v)
    indegree[u] += 1

q = PriorityQueue()
for _ in range(n):
    if indegree[_] == 0:
        q.put(_)
cnt = 0
while q.qsize():
    u = q.get()
    order.append(u)
    cnt += 1
    for v in lst[u]:
        indegree[v] -= 1
        if indegree[v] == 0:
            q.put(v)
if cnt != n:
    print("Not exist Topological")
else:
    print(*order)

