'''
Author: NEFU AB-IN
Date: 2022-03-16 16:29:18
FilePath: \ACM\LanQiao\2021E.py
LastEditTime: 2022-03-16 16:48:17
'''
N = 21
M = 1 << 21
import math


def gcd(a, b):
    return gcd(b, a % b) if b else a


dp = [[0] * N for _ in range(M)]
g = [[0] * N for _ in range(N)]

for i in range(1, 22):
    for j in range(i + 1, 22):
        if gcd(i, j) == 1:
            g[i - 1][j - 1] = g[j - 1][i - 1] = 1

dp[1][0] = 1
for i in range(M):
    for j in range(N):
        if i >> j & 1:
            pre = i - (1 << j)
            for k in range(N):
                if g[j][k] and (pre >> k & 1):
                    dp[i][j] += dp[pre][k]

res = 0
for i in range(1, 22):
    res += dp[M - 1][i - 1]
print(res)