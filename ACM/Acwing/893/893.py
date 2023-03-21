'''
Author: NEFU AB-IN
Date: 2023-03-21 21:12:31
FilePath: \Acwing\893\893.py
LastEditTime: 2023-03-21 22:05:59
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e5 + 10)
INF = int(2e9)
f = [-1] * N
# f 代表状态 因为S集合中的数的值最大为10000

def sg(x):
    if f[x] != -1:
        return f[x]

    d = Counter()
    for i in s:
        if x >= i:
            d[sg(x - i)] = 1

    for i in range(INF):
        if d[i] == 0:
            f[x] = i
            return f[x]


k = int(input())
s = list(read())

n = int(input())
h = list(read())

res = 0
for i in h:
    res ^= sg(i)

print("Yes" if res != 0 else "No")