'''
Author: NEFU AB-IN
Date: 2023-03-19 19:57:48
FilePath: \Acwing\1394\1394.py
LastEditTime: 2023-03-19 20:06:26
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(210)
INF = int(2e9)

st, lk = [0] * N, [0] * N
g = [[] for _ in range(N)]

def dfs(u):
    for v in g[u]:
        if st[v] == 0:
            st[v] = 1
            if lk[v] == 0 or dfs(lk[v]):
                lk[v] = u
                return True
    return False


n, m = read()
for i in range(1, n + 1):
    tmp = list(read())
    for j in tmp[1:]:
        g[i].append(j)

ans = 0
for i in range(1, n + 1):
    if dfs(i):
        ans += 1
print(ans)