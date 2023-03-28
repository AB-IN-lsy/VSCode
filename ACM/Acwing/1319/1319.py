'''
Author: NEFU AB-IN
Date: 2023-03-23 20:36:19
FilePath: \Acwing\1319\1319.py
LastEditTime: 2023-03-23 20:46:55
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(2e3 + 10)
INF = int(2e9)
f = [-1] * N


def sg(u):
    if f[u] != -1:
        return f[u]

    d = Counter()
    for v in g[u]:
        d[sg(v)] = 1

    for i in range(INF):
        if d[i] == 0:
            f[u] = i
            return i


g = [[] for _ in range(N)]
n, m, k = read()

for i in range(m):
    x, y = read()
    g[x].append(y)

res = 0
lst = list(read())
for i in lst:
    res ^= sg(i)

print("win" if res != 0 else "lose")