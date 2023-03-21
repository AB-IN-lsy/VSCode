'''
Author: NEFU AB-IN
Date: 2023-03-20 16:27:52
FilePath: \Acwing\4469\4469.py
LastEditTime: 2023-03-20 17:39:01
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(2e3 + 10)
INF = int(2e9)
MOD = 998244353

# dp[i][j]表示前i位有j个不同的方案数
dp = [[0] * N for _ in range(N)]
n, m, k = read()

for i in range(1, n + 1):
    dp[i][0] = m

for i in range(2, n + 1):
    for j in range(1, k + 1):
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (m - 1) % MOD

print(dp[n][k])
