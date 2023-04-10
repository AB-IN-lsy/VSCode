# AB-IN AK Lanqiao !!
import sys, math
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from typing import *
from datetime import datetime, timedelta

N = int(1e3 + 10)
MOD = 998244353
INF = int(2e9)

sys.setrecursionlimit(INF)
read = lambda : map(int, input().split())

class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __lt__(self, x):
        pass

# ---------------divrsion line ----------------
# RMQ 问题 可写ST表 但我忘了...
# 暴力！
g = [[0] * N for _ in range(N)]
n, m, a, b = read()

def func(t1, t2):
    mn, mx = INF, 0
    for i in range(t1.x, t2.x + 1):
        for j in range(t1.y, t2.y + 1):
            mn = min(mn, g[i][j])
            mx = max(mx, g[i][j])
    return mx * mn % MOD

for i in range(1, n + 1):
    g[i][1:] = read()

ans = 0
for i in range(1, n + 1):
    for j in range(1, m + 1):
        t1 = sa(i, j)
        t2 = sa(i + a - 1, j + b - 1)
        if i + a - 1 > n or j + b - 1 > m:
            continue
        ans = (ans + func(t1, t2)) % MOD 

print(ans)