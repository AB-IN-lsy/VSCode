# AB-IN AK Lanqiao !!
import sys, math
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from typing import *
from datetime import datetime, timedelta

N = int(1e5 + 10)
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
# 暴力！
# 预处理1 ~ 5000阶乘
dd = Counter()
cnt = 1
for i in range(1, 5000):
    cnt *= i
    dd[i] = cnt
# ---------------------------------------------
a = [0] * N

n, = read()
a[1:] = list(read())
d = Counter()

base = min(a[1:])
ans = 0
for i in range(1, n + 1):
    tmp = 1
    if a[i] < 5000:
        d[a[i]] = dd[a[i]] // dd[base]
    elif d[a[i]] == 0:
        for j in range(a[i], base, -1):
            tmp *= j
        d[a[i]] = tmp
    ans += d[a[i]]

while True:
    if ans == 1 or ans % (base + 1) != 0:
        break
    base += 1
    ans //= base

print(base)