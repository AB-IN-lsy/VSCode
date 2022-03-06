'''
Author: NEFU AB-IN
Date: 2021-11-05 19:16:12
FilePath: \ACM\test.py
LastEditTime: 2022-03-05 17:25:05
'''
N = int(100)
INF = int(2e9)
dp, a = [0] * N, [0] * N

n = int(input())
a[1:] = map(int, input().split())

maxn = -INF
for i in range(1, n + 1):
    dp[i] = max(a[i], dp[i - 1] + a[i])
    maxn = max(maxn, dp[i])

print(maxn)