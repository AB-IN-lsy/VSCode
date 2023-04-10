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
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def __lt__(self, t):
        if self.a != t.a:
            return self.a < t.a
        return self.b < t.b

# ---------------divrsion line ----------------

n, = read()
lst = [[] for _ in range(10)]

for i in range(n):
    a, b = read()
    lst[a].append(b)

for i in range(10):
    lst[i].sort()
    lst[i] = [0, *lst[i]]
    # 前缀和
    for j in range(1, len(lst[i])):
        lst[i][j] += lst[i][j - 1]

# 保留的个数
k = n // 10

ans = 0
for i in range(10):
    l = len(lst[i]) - 1
    if l > k:
        ans += (lst[i][l - k])

print(ans)