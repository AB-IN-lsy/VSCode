'''
Author: NEFU AB-IN
Date: 2022-03-06 12:10:10
FilePath: \ACM\Acwing\3.1.py
LastEditTime: 2022-06-20 23:12:03
'''
n, m = map(int, input().split())

N = 1100
v, w = [0] * N, [0] * N
dp = [[0] * N for _ in range(N)]

for i in range(1, n + 1):
    v[i], w[i] = map(int, input().split())

for i in range(1, n + 1):
    for j in range(0, m + 1):
        k = 0
        while k * v[i] <= j:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] * k] + w[i] * k)
            k += 1

print(dp[n][m])