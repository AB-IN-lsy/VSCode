'''
Author: NEFU AB-IN
Date: 2023-06-15 14:46:06
FilePath: \Acwing\4908\4908.py
LastEditTime: 2023-07-06 01:03:20
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
N = int(1e3 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
AR = lambda x=0: [x] * N

# —————————————————————Division line ——————————————————————
a = AR(0)

st, ed = -1, -1
res = 0
n, t = read()

for i in range(n):
    d, b = read()
    l, r = d, min(d + b - 1, t)
    if ed < l:
        if st != -1:
            res += ed - st + 1
        st, ed = l, r
    else:
        ed = min(t, ed + b)

if st != -1:
    res += min(ed, t) - st + 1

print(res)
