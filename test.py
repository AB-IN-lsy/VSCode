'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-01-28 23:02:48
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 15:09:55
'''
from collections import deque

def find_girth(adj_list):
    girth = float('inf')
    for n in range(len(adj_list)):
        color = []
        d = []
        for i in range(len(adj_list)):
            color.append(0)
            if i == n:
                d.append(0)
            else:
                d.append(float('inf'))
        cyc_len = bfs_visit(adj_list, n, color, d)
        if girth > cyc_len:
            girth = cyc_len
    return girth
    
def bfs_visit(adj_list, s, color, d):
    q = deque()
    q.append(s)
    color[s] = 1
    while len(q) > 0:
        r = q[0]
        shortest_cycle = float('inf')
        for j in adj_list[r]:
            if color[j] == 0:
                color[j] = 1
                q.append(j)
                d[j] = d[r] + 1
            elif color[j] == 1:
                if shortest_cycle > d[j] + d[r] + 1:
                    shortest_cycle = d[j] + d[r] + 1
        if shortest_cycle < float('inf'):
            return shortest_cycle
        q.popleft()
        color[r] = 2
    return float('inf')

adj_list = [[1,2],[0,4,5],[0,3,5],[2,6],[1,6,7],[1,2,7],[3,4,8],[4,5,8],[6,7]]
print(find_girth(adj_list))