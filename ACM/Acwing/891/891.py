'''
Author: NEFU AB-IN
Date: 2023-03-21 10:19:25
FilePath: \Acwing\891\891.py
LastEditTime: 2023-03-21 10:22:32
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e3 + 10)
INF = int(2e9)

n = int(input())
lst = list(read())

res = 0
for i in lst:
    res ^= i

print("Yes" if res != 0 else "No")