'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-25 11:01:35
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 11:47:03
'''
cnt = 0
def dfs_r(x, lst, color, done):
    if color[x] == 1:
        return
    global cnt
    color[x] = 1
    for v in lst[x]:
        dfs_r(v, lst, color, done)
    done[x] = cnt
    cnt += 1

def dfs(x, lst, ans, done, start):
    if ans[x] != -1:
        return
    ans[x] = start
    done[x] = -1
    for v in lst[x]:
        dfs(v, lst, ans, done, start)

def find_scc(adj_lists):
    n = len(adj_lists)
    ans = [-1 for _ in range(n)]
    adj_lists_r = [[] for _ in range(n)]
    for i in range(n):
        for j in adj_lists[i]:
            adj_lists_r[j].append(i)
    color = [0 for _ in range(n)]
    done = [-1 for _ in range(n)]

    while -1 in done: # done all the nodes
        start = done.index(-1)
        dfs_r(start, adj_lists_r, color, done)
    
    while done != [-1] * n:# find every time the biggest the index of the done value
        start = done.index(max(done))
        dfs(start, adj_lists, ans, done, start)
    print(ans)

find_scc([[2, 3], [0], [1], [4], []])