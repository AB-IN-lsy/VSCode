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
# 两种糖果分别有 9 个和 16 个，要全部分给 7 个小朋友，每个小朋友得到
# 的糖果总数最少为 2 个最多为 5 个，问有多少种不同的分法。

ans = 0
def dfs(sum1, sum2, cnt):
    global ans
    if sum1 < 0 or sum2 < 0:
        return
    if cnt == 8:
        if sum1 == 0 and sum2 == 0:
            ans += 1
        return
    for i in range(2, 6):
        dfs(sum1 - i, sum2, cnt + 1)
    for i in range(2, 6):
        dfs(sum1, sum2 - i, cnt + 1)
    for i in range(2, 6):
        for j in range(2, 6):
            if i + j >= 2 and i + j <= 5:
                dfs(sum1 - i, sum2 - j, cnt + 1)

dfs(9, 16, 1)
print(ans)

# 148540