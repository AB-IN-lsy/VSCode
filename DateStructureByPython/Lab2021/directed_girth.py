'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-25 19:52:01
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 20:20:46
'''
from queue import Queue

def find_directed_girth(adj_list):
    n = len(adj_list)
    inf = float('inf')
    ans = inf
    for i in range(n):
        q = Queue()
        q.put(i)
        color = [0 for _ in range(n)]
        d = [inf for _ in range(n)]
        flag = 0
        d[i] = 0
        color[i] = 1
        while q.qsize():
            u = q.get()
            for v in adj_list[u]:
                if v == i:
                    ans = min(1 + d[u], ans)
                    flag = 1
                    break
                if color[v] == 0:
                    q.put(v)
                    color[v] = 1
                    d[v] = d[u] + 1
            if flag == 1:
                break
    return ans

adj_list = [[], [2], [4], [2], [3], [1]]
print(find_directed_girth(adj_list))
# 3
# 2 -> 4 -> 3 -> 2
adj_list = [[], [2, 5], [4], [2], [3], [1]]
print(find_directed_girth(adj_list))

# 2
# 1 -> 5 -> 1