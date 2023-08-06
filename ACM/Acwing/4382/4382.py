'''
Author: NEFU AB-IN
Date: 2023-07-08 21:41:05
FilePath: \Acwing\4382\4382.py
LastEditTime: 2023-07-09 00:24:30
'''
# import
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor


class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, a):
        return self.x < a.x


# Final
N = int(1e5 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
AR = lambda x=0: [x] * N

# —————————————————————Division line ——————————————————————

t, = read()

for _ in range(t):
    I = input()
    p = input()

    j, cnt, flag = 0, 0, 0
    for i in range(len(I)):
        while j < len(p) and I[i] != p[j]:
            j += 1
            cnt += 1
        if j >= len(p):
            flag = 1
            print(f"Case #{_ + 1}: IMPOSSIBLE")
            break
        if I[i] == p[j]:
            j += 1
    if flag == 0:
        print(f"Case #{_ + 1}: {cnt + len(p) - j}")