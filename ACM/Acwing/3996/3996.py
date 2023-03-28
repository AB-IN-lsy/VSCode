'''
Author: NEFU AB-IN
Date: 2023-03-24 17:07:53
FilePath: \Acwing\3996\3996.py
LastEditTime: 2023-03-24 19:48:13
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(5e3 + 10)
INF = int(2e9)

n = int(input())
c1 = list(read())
c = [0]
dp = [[0] * N for _ in range(N)]

for i in range(n):
    if i == 0 or c1[i] != c1[i - 1]:
        c.append(c1[i])

n = len(c) - 1
for len in range(2, n + 1):
    l, r = 1, len
    while r <= n:
        dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1
        if c[l] == c[r]:
            dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1)
        l += 1
        r += 1

print(dp[1][n])