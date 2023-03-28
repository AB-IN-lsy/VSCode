'''
Author: NEFU AB-IN
Date: 2023-03-22 22:16:04
FilePath: \Acwing\894\894.py
LastEditTime: 2023-03-22 22:23:37
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(2e3 + 10)
INF = int(2e9)
f = [-1] * N


def sg(x):
    if f[x] != -1:
        return f[x]

    d = Counter()
    for i in range(x):
        for j in range(i + 1):
            d[sg(i) ^ sg(j)] = 1

    for i in range(INF):
        if d[i] == 0:
            f[x] = i
            return f[x]


n = int(input())
res = 0

lst = list(read())
for i in lst:
    res ^= sg(i)

print("Yes" if res != 0 else "No")