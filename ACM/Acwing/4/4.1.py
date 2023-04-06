'''
Author: NEFU AB-IN
Date: 2023-03-31 20:53:43
FilePath: \Acwing\4\4.1.py
LastEditTime: 2023-03-31 20:55:59
'''
# import
import sys, math
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

# Final
N = int(1e2 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
read = lambda: map(int, input().split())

# —————————————————————Division line ————————————————————————————————————————

n, m = read()
v, w, s = [0] * N, [0] * N, [0] * N
dp = [0] * N

for i in range(1, n + 1):
    v[i], w[i], s[i] = map(int, input().split())

for i in range(1, n + 1):
    for j in range(m, -1, -1):
        k = 0
        while k <= s[i] and k * v[i] <= j:
            dp[j] = max(dp[j], dp[j - v[i] * k] + w[i] * k)
            k += 1

print(dp[m])