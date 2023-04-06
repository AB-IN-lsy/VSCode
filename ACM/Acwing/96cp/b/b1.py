'''
Author: NEFU AB-IN
Date: 2023-03-31 16:28:46
FilePath: \Acwing\96cp\b\b1.py
LastEditTime: 2023-03-31 21:09:10
'''
# import
import sys, math
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

# Final
N = int(1e3 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
read = lambda: map(int, input().split())

# —————————————————————Division line ————————————————————————————————————————

dp = [0] * N

n, m, v, w = read()

for j in range(v, n + 1):
    dp[j] = dp[j - v] + w

for i in range(m):
    l, h, v, w = read()
    for j in range(n, -1, -1):
        k = 0
        while k <= l / h and j - k * v >= 0:
            dp[j] = max(dp[j], dp[j - k * v] + k * w)
            k += 1

print(dp[n])