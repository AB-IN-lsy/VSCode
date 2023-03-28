'''
Author: NEFU AB-IN
Date: 2023-03-25 18:49:28
FilePath: \Acwing\4005\4005.py
LastEditTime: 2023-03-25 18:54:33
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e3 + 10)
INF = int(2e9)
f = [-1] * N
# 打表代码

def sg(x):
    if f[x] != -1:
        return f[x]
    
    d = Counter()
    for i in lst:
        if x >= i:
            d[sg(x - i)] = 1
    
    for i in range(INF):
        if d[i] == 0:
            f[x] = i
            return f[x]


k = int(input())

lst = [1, 2, k]

for i in range(0, 20):
    print(i, sg(i))