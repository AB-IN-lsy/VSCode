# AB-IN AK Lanqiao !!
import sys, math
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from typing import *
from datetime import datetime, timedelta

N = int(1e6 + 10)
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
# 最差方法 二进制枚举

n, = read()
a = list(read())
b = list(read())
c = list(read())
ans = 0

for i in range(1 << n):
    A, B, C, cnt = 0, 0, 0, 0
    for j in range(n):
        if i & 1 << j:
            A += a[j]
            B += b[j]
            C += c[j]
            cnt += 1
    if A > B + C or B > A + C or C > A + B:
        ans = max(ans, cnt)

print(ans if ans != 0 else -1)
