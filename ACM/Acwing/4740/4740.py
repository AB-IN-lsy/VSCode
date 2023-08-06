'''
Author: NEFU AB-IN
Date: 2023-07-09 00:47:29
FilePath: \Acwing\4740\4740.py
LastEditTime: 2023-07-09 01:55:01
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
    L, cnt, C = 0, 0, 0

    l, n = read()
    for i in range(n):
        d, c = input().split()
        d = int(d)
        if i == 0:
            C = c
        if c == C:
            L += d
            cnt += L // l
        else:
            if L >= 0 and L - d < 0:
                C = c
            L -= d
            if L < 0:
                L = -L
                cnt += L // l
        L %= l
    print(f"Case #{_ + 1}: {cnt}")