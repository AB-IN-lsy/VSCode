'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-25 10:59:39
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 15:14:11
'''
from queue import Queue

def find_girth(adj_list):
    n = len(adj_list)
    inf = float('inf')
    girth = inf
    for i in range(n):
        short_tmp = inf
        color = [0 for _ in range(n)]
        d = [inf for _ in range(n)]
        d[i] = 0
        color[i] = 1
        q = Queue()
        q.put(i)
        while q.qsize():
            u = q.get()
            for v in adj_list[u]:
                if color[v] == 1:
                    short_tmp = min(short_tmp, d[u] + d[v] + 1)
                    continue
                if color[v] == 0:
                    color[v] = 1
                    q.put(v)
                    d[v] = d[u] + 1
            if short_tmp < float('inf'):
                girth = min(girth, short_tmp)
                break
            color[u] = 2 # key point, means this vertex is done
    return girth

adj_list = [[1,2],[0,4,5],[0,3,5],[2,6],[1,6,7],[1,2,7],[3,4,8],[4,5,8],[6,7]]
print(find_girth(adj_list))


    