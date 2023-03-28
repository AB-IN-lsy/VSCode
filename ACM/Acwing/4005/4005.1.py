'''
Author: NEFU AB-IN
Date: 2023-03-25 18:57:14
FilePath: \Acwing\4005\4005.1.py
LastEditTime: 2023-03-25 19:00:55
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e3 + 10)
INF = int(2e9)
# 正式代码

for _ in range(int(input())):
    n, k = read()
    if k % 3:
        if n % 3:
            print("Alice")
        else:
            print("Bob")
    else:
        ys = n % (k + 1)
        if ys % 3 == 0 and ys != k:
            print("Bob")
        else:
            print("Alice")