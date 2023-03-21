'''
Author: NEFU AB-IN
Date: 2023-03-21 19:11:38
FilePath: \Acwing\892\892.py
LastEditTime: 2023-03-21 21:12:27
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e3 + 10)
INF = int(2e9)

n = int(input())
lst = [0] + list(read())

ans = 0
for i in range(1, len(lst)):
    if i & 1:
        ans ^= lst[i]

print("Yes" if ans != 0 else "No")893