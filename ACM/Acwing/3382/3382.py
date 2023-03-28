'''
Author: NEFU AB-IN
Date: 2023-03-23 16:16:15
FilePath: \Acwing\3382\3382.py
LastEditTime: 2023-03-23 19:43:52
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e6 + 10)
INF = int(2e9)
MOD = int(1e9)
dp = [0] * N

n = int(input())
dp[0] = 1

i = 1
while i <= n:
    for j in range(i, n + 1):
        dp[j] = (dp[j] + dp[j - i]) % MOD
    i *= 2

print(dp[n])