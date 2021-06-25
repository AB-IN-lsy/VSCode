'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-25 10:20:19
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 10:40:15
'''
from queue import PriorityQueue
# 优化，即顺序按照字典序输出

def schedule(dep):
    # start with 0
    n = len(dep)
    indegree = [0 for _ in range(n)]
    lst = [[] for _ in range(n)]
    order = []
    for i in range(n):
        for j in dep[i]:
            lst[j].append(i)
            indegree[i] += 1
    
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
        return None
    else:
        return order

dep = [[1,2],[3,5],[3],[6,7,8],[5],[6,9],[8],[8],[9],[]]
print(schedule(dep))
